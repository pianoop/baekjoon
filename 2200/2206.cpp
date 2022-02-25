//벽 부수고 이동하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int N, M;
int nextx[4] = { -1,1,0,0 };
int nexty[4] = { 0,0,-1,1 };

class PosS
{
public:
	int x, y, state;

	PosS(int a, int b, int c) :x(a), y(b), state(c) {}
};



int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> N >> M;

	vvi map0(N + 2, vi(M + 2, 0));
	for (int i = 1;i <= N;i++)
	{
		std::string s;
		std::cin >> s;
		int j = 1;
		for (auto& a : s)
		{
			if (a == 48)
				map0[i][j] = -1;
			else
				map0[i][j] = -2;
			j++;
		}
	}
	vvi map1 = map0;
	map0[1][1] = 1;
	std::queue<PosS> box;
	box.push(PosS(1, 1, 0));
	bool flag = 1;
	int x, y, WB;
	while (!box.empty())
	{
		x = box.front().x, y = box.front().y, WB = box.front().state;
		if (x == N && y == M)
		{
			flag = 0;
			if (WB == 0)
				std::cout << map0[x][y];
			else
				std::cout << map1[x][y];
			break;
		}

		if (WB == 0)
		{
			for (int nx,ny, i = 0;i < 4;i++)
			{
				nx = x + nextx[i], ny = y + nexty[i];
				if (map0[nx][ny] == -1)
				{
					map0[nx][ny] = map0[x][y] + 1;
					box.push(PosS(nx, ny, 0));
				}
				else if (map0[nx][ny] == -2)
				{
					map1[nx][ny] = map0[x][y] + 1;
					box.push(PosS(nx, ny, 1));
				}
			}
		}
		else
		{
			for (int nx, ny, i = 0;i < 4;i++)
			{
				nx = x + nextx[i], ny = y + nexty[i];
				if (map0[nx][ny] == -2)
					continue;
				if (map0[nx][ny]== -1 &&map1[nx][ny] == -1)
				{
					map1[nx][ny] = map1[x][y] + 1;
					box.push(PosS(nx, ny, 1));
				}
			}
		}
		box.pop();
	}
	
	if (flag)
		std::cout << "-1";

	return 0;
}