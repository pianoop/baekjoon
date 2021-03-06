//파이프 옮기기 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vvi map(N + 1, vi(N + 1));
	for (int i = 1;i < N + 1;i++)
		for (int j = 1;j < N + 1;j++)
			std::cin >> map[i][j];
	if (map[1][3] == 1)
	{
		std::cout << "0";
		return 0;
	}


	vvi DP[3];
	DP[0].resize(N + 1, vi(N + 1)), DP[1].resize(N + 1, vi(N + 1)), DP[2].resize(N + 1, vi(N + 1));
	DP[0][1][2] = 1;

	for (int i = 1;i < N + 1;i++)
	{
		for (int j = 3;j < N + 1;j++)
		{
			if (map[i][j] != 1)
			{
				DP[0][i][j] += DP[0][i][j - 1] + DP[2][i][j - 1];
				DP[1][i][j] += DP[1][i - 1][j] + DP[2][i - 1][j];
				if (map[i - 1][j] != 1 && map[i][j - 1] != 1)
					DP[2][i][j] += DP[0][i - 1][j - 1] + DP[1][i - 1][j - 1] + DP[2][i - 1][j - 1];
			}
		}
	}

	std::cout << DP[0][N][N] + DP[1][N][N] + DP[2][N][N];

	return 0;
}