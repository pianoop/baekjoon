//토마토(2차원)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int N, M, Max=1;
int nextx[4] = { -1,1,0,0 };
int nexty[4] = { 0,0,-1,1 };

void BFS( vvi& map, std::queue<std::pair<int, int> >& box)
{
	int x, y;
	while (!box.empty())
	{
		x = box.front().first, y = box.front().second;

		for (int i = 0;i < 4;i++)
		{
			int nx = x + nextx[i], ny = y + nexty[i];
			if (map[nx][ny] == 0)
			{
				box.push({ nx,ny });
				map[nx][ny] = map[x][y] + 1;
			}
		}
		if (map[x][y] > Max)
			Max = map[x][y];
		box.pop();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> M >> N;

	vvi map(N + 2, vi(M + 2,-1));
	std::queue<std::pair<int, int> > box;
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= M;j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 1)
				box.push({ i,j });
		}
	}

	BFS(map,box);
	
	bool test=0;
	for (auto& a : map)
	{
		for (auto& b : a)
		{
			if (b == 0) 
			{
				test = 1;
				break;
			}
		}
		if (test)
			break;
	}

	if (test)
		std::cout << "-1";
	else
		std::cout << Max-1;

	return 0;
}