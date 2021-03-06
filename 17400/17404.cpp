//RGB거리 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <array>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	const int Max = int(1e8);
	int N;
	std::cin >> N;

	std::vector<std::array<int, 3> > cost(N);
	for (auto& a : cost)
		for (auto& b : a)
			std::cin >> b;

	std::vector<std::array<int, 3> > DP[3];
	DP[0].resize(N), DP[1].resize(N), DP[2].resize(N);
	for (int i = 0;i < 3;i++)
		DP[i][0][i] = cost[0][i];
	DP[0][0][1] = DP[0][0][2] = DP[1][0][0] = DP[1][0][2] = DP[2][0][0] = DP[2][0][1] = Max;

	for (int first = 0;first < 3;first++)
	{
		for (int i = 1;i < N;i++)
		{
			DP[first][i][0] = std::min(DP[first][i - 1][1], DP[first][i - 1][2]) + cost[i][0];
			DP[first][i][1] = std::min(DP[first][i - 1][0], DP[first][i - 1][2]) + cost[i][1];
			DP[first][i][2] = std::min(DP[first][i - 1][0], DP[first][i - 1][1]) + cost[i][2];
		}
	}

	N--;
	int min = std::min(DP[0][N][1], DP[0][N][2]);
	min = std::min(min, std::min(DP[1][N][0], DP[1][N][2]));
	min = std::min(min, std::min(DP[2][N][0], DP[2][N][1]));

	std::cout << min;

	return 0;
}