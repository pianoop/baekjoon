//1, 2, 3 더하기 5
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int dp[100'001][3];

void Solve()
{
	const int DIV = 1'000'000'009;
	dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;

	int prev1 = 1, prev2 = 2, prev3 = 3;
	for (int i = 4; i < 100'001; i++)
	{
		dp[i][0] = (dp[prev3][1] + dp[prev3][2])%DIV;
		dp[i][1] = (dp[prev2][0] + dp[prev2][2])%DIV;
		dp[i][2] = (dp[prev1][0] + dp[prev1][1])%DIV;

		prev1 = prev2;
		prev2 = prev3;
		prev3 = i;
	}

	int T, input;
	std::cin >> T;
	while (T--)
	{
		std::cin >> input;
		std::cout << ((dp[input][0] + dp[input][1])%DIV + dp[input][2])%DIV<<"\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}