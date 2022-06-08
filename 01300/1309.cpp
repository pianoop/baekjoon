//동물원
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

void Solve()
{
	int n;
	std::cin >> n;
	
	vi dp(n + 1);
	dp[0] = 1, dp[1] = 3;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;

	std::cout << dp[n];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}