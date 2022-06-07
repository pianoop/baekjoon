//합분해
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


void Solve()
{
	const int DIV = 1'000'000'000;

	int n, k;
	std::cin >> n >> k;

	if (k == 1)
	{
		std::cout << 1;
		return;
	}

	n++, k++;
	vvi dp(k, vi(n)); //dp[k개의 수를 사용하여][N을 만드는데 필요한 가짓수]

	for (auto& i : dp[1]) //dp[1][~] = 1 초기화
		i = 1;
	for (int j = 0; j < n; j++)
		dp[2][j] = j + 1;

	int prev = 2;
	for (int i = 3; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[prev][k]) % DIV;
			}
		}

		prev = i;
	}

	std::cout << dp[k - 1][n - 1];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}