//제곱수의 합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;


void Solve()
{
	int n;
	std::cin >> n;

	vi dp(n + 1,0x7FFFFFFF), nums;
	dp[0] = 0;
	for (int i = 1, ii = 1; ii <= n; i++, ii = i * i)
	{
		dp[ii] = 1;
		nums.push_back(ii);
	}

	for (int i = 2; i <= n; i++)
	{
		for (auto num : nums)
		{
			if (num >= i)
				break;

			dp[i] = std::min(dp[i], dp[num] + dp[i - num]);
		}
	}

	std::cout << dp[n];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}