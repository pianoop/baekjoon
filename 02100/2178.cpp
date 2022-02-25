//미로 탐색
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int N, M;
int nextx[4] = { -1,1,0,0 };
int nexty[4] = { 0,0,-1,1 };

void BFS( vvi& map)
{
	
	std::queue<std::pair<int, int> > box;
	box.push({ 1,1 });
	int x, y;
	map[1][1] = 1;
	while (!box.empty())
	{
		x = box.front().first, y = box.front().second;

		if (x == N && y == M)
			return;
		for (int i = 0;i < 4;i++)
		{
			int nx = x + nextx[i], ny = y + nexty[i];
			if (map[nx][ny] == 0)
			{
				box.push({ nx,ny });
				map[nx][ny] = map[x][y] + 1;
			}
		}
		box.pop();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> N >> M;

	vvi map(N + 2, vi(M + 2,1));
	for (int i = 1;i <= N;i++)
	{
		std::string s;
		std::cin >> s;
		int j = 1;
		for (auto& a : s)
		{
			if (a == 49)
				map[i][j] = 0;
			j++;
		}
	}

	BFS(map);
	
	std::cout << map[N][M];

	return 0;
}