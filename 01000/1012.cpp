//유기농 배추
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int N, M;
int nextx[4] = { 1,-1,0,0 };
int nexty[4] = { 0,0,-1,1 };

void DFS(int x, int y, vvi& map)
{
	map[x][y] = 2;
	for (int i = 0;i < 4;i++)
	{
		if (map[x + nextx[i]][y + nexty[i]] == 1)
			DFS(x + nextx[i], y + nexty[i], map);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
	{
		int K, ans=0;
		std::cin >> M >> N >> K;

		vvi map(N + 2, vi(M + 2));
		for (int x, y, i = 0;i < K;i++)
		{
			std::cin >> x >> y;
			map[y + 1][x + 1] = 1;
		}

		for (int i = 1;i <= N;i++)
		{
			for (int j = 1;j <= M;j++)
			{
				if (map[i][j] == 1)
				{
					DFS(i, j, map);
					ans++;
				}
			}
		}

		std::cout << ans << "\n";
	}
	return 0;
}