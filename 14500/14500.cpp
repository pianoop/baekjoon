//테트로미노
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int Max = 0;
int N, M;

void DP(int n, int t, int x, int y, const vvi& p, int lru)
{
	if (n == 4)
	{
		if (Max < t)
			Max = t;
		return;
	}
	if (x != N)
		DP(n + 1, t + p[x + 1][y], x + 1, y, p, 3);
	if (y != M && lru != 1)
	{
		DP(n + 1, t + p[x][y + 1], x, y + 1, p, 2);
		if (n < 3 && x != N)
		{
			DP(n + 2, t + p[x][y + 1] + p[x + 1][y], x, y + 1, p, 2);
			DP(n + 2, t + p[x][y + 1] + p[x + 1][y], x + 1, y, p, 3);
		}
	}
	if (y != 1 && lru != 2)
	{
		DP(n + 1, t + p[x][y - 1], x, y - 1, p, 1);
		if (n == 2)
		{
			if (x != N)
				DP(n + 2, t + p[x][y - 1] + p[x + 1][y], 0, 0, p, 0);
			if (y != M && lru==3)
				DP(n + 2, t + p[x][y - 1] + p[x][y + 1], 0, 0, p, 0);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> N >> M;

	vvi paper(N + 1, vi(M + 1));
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= M;j++)
			std::cin >> paper[i][j];

	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= M;j++)
			DP(1, paper[i][j], i, j, paper, 0);


	std::cout << Max;

	return 0;
}