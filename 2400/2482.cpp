//색상환
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int div = 1'000'000'003;
	int N, K;
	std::cin >> N >> K;

	if (N / K < 2)
		std::cout << 0;
	else if (N == K * 2)
		std::cout << 2;
	else if (K == 1)
		std::cout << N;
	else
	{
		vvi DP(N + 1, vi(K + 1, 0));
		for (int i = 2;i <= N ;i++)
		{
			DP[i][1] = i;
			for (int j = 2;j < i / 2 + 1 && j <= K;j++)
			{
				DP[i][j] = (DP[i - 1][j] + DP[i - 2][j - 1]) % div;
			}
		}

		std::cout << DP[N][K];
	}

	return 0;
}