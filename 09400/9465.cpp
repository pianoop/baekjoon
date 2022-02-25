//스티커
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T, N;
	std::cin >> T;

	while (T--)
	{
		std::cin >> N;
		vi stc0(N+2), stc1(N+2);
		std::for_each(stc0.begin(), stc0.end() - 2, [](int& a)
			{
				std::cin >> a;
			});
		std::for_each(stc1.begin(), stc1.end() - 2, [](int& a)
			{
				std::cin >> a;
			});

		vi DP[2];
		DP[0].resize(N + 2), DP[1].resize(N + 2);
		DP[0][0] = stc0[0], DP[1][0] = stc1[0];

		for (int i = 0;i < N;i++)
		{
			if (DP[0][i + 1] < DP[1][i] + stc0[i + 1])
				DP[0][i + 1] = DP[1][i] + stc0[i + 1];
			if (DP[0][i + 2] < DP[1][i] + stc0[i + 2])
				DP[0][i + 2] = DP[1][i] + stc0[i + 2];

			if (DP[1][i + 1] < DP[0][i] + stc1[i + 1])
				DP[1][i + 1] = DP[0][i] + stc1[i + 1];
			if (DP[1][i + 2] < DP[0][i] + stc1[i + 2])
				DP[1][i + 2] = DP[0][i] + stc1[i + 2];
		}
		std::cout << (DP[0][N - 1] > DP[1][N - 1] ? DP[0][N - 1] : DP[1][N - 1]) << "\n";
	}

	return 0;
}