//토마토
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Triple
{
public:
	int _x, _y, _z;

	Triple(int a, int b, int c) :_x(a), _y(b), _z(c) {}
};

int Max = 1;
int nextx[6] = { -1,1,0,0,0,0 };
int nexty[6] = { 0,0,-1,1,0,0 };
int nextz[6] = { 0,0,0,0,-1,1 };

void BFS(std::vector<vvi>& map, std::queue<Triple>& box)
{
	int x, y, z;
	while (!box.empty())
	{
		x = box.front()._x, y = box.front()._y, z = box.front()._z;

		for (int i = 0;i < 6;i++)
		{
			int nx = x + nextx[i], ny = y + nexty[i], nz = z + nextz[i];
			if (map[nx][ny][nz] == 0)
			{
				box.push(Triple(nx, ny, nz));
				map[nx][ny][nz] = map[x][y][z] + 1;
			}
		}
		if (map[x][y][z] > Max)
			Max = map[x][y][z];
		box.pop();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M, H;
	std::cin >> M >> N >> H;

	std::vector<vvi> map(N + 2, vvi(M + 2, vi(H + 2, -1)));
	std::queue<Triple> box;
	for (int k = 1;k <= H;k++)
	{
		for (int i = 1;i <= N;i++)
		{
			for (int j = 1;j <= M;j++)
			{
				std::cin >> map[i][j][k];
				if (map[i][j][k] == 1)
					box.push(Triple(i, j, k));
			}
		}
	}

	BFS(map, box);

	bool test = 0;
	for (auto& a : map)
	{
		for (auto& b : a)
		{
			for (auto& c : b)
			{
				if (c == 0)
				{
					test = 1;
					break;
				}
			}
			if (test)
				break;
		}
		if (test)
			break;
	}

	if (test)
		std::cout << "-1";
	else
		std::cout << Max - 1;

	return 0;
}