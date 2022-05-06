//퇴사
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

void Solve()
{
	int n;
	std::cin >> n;
	vi dp(n + 1);

	int d, cost;
	for (int i = 0; i < n; i++)
	{
		std::cin >> d >> cost;

		int next = i + d;
		if (next <= n)
			dp[next] = std::max(dp[next], dp[i] + cost);

		next = i + 1;
		dp[next] = std::max(dp[next], dp[i]);
	}

	std::cout << dp[n];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}