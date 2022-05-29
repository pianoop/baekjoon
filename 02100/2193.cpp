//이친수
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


void Solve()
{
	int N;
	std::cin >> N;

	long long dp[91][2];
	dp[1][1] = dp[2][0] = 1;
	dp[1][0] = dp[2][1] = 0;
	int prev = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i][0] = dp[prev][0] + dp[prev][1];
		dp[i][1] = dp[prev][0];
		prev = i;
	}

	std::cout << dp[N][0] + dp[N][1];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}