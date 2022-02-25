//내리막 길
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int n_row[4] = { -1,1,0,0 };
int n_col[4] = { 0,0,-1,1 };
int M, N;

int dpmaping(const int& m, const int& n, vvi& map, vvi& dp)
{
	int& nowh = map[m][n];
	if (nowh == -1)
		return 0;

	if (m == M && n == N)
		return 1;

	int& nowdp = dp[m][n];
	if (nowdp != -1)
		return nowdp;

	nowdp = 0;
	for (int i = 0;i < 4;i++)
	{
		int nm = m + n_row[i];
		int nn = n + n_col[i];
		if (nowh > map[nm][nn])
			nowdp += dpmaping(nm, nn, map, dp);
	}
	return nowdp;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> M >> N;

	vvi map(M + 2, vi(N + 2, -1));
	for (int i = 1;i <= M;i++)
	{
		for (int j = 1;j <= N;j++)
			std::cin >> map[i][j];
	}

	vvi DP(M + 2, vi(N + 2, -1));
	dpmaping(1, 1, map, DP);

	std::cout << dpmaping(1, 1, map, DP);

	return 0;
}