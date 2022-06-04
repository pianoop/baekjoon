//동전 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;


void Solve()
{
	const int MAX = 0x7FFFFFFF;
	int n, k;
	std::cin >> n >> k;

	vi dp(k + 1,MAX), coins;
	dp[0] = 0;
	for (int i = 0, tmp; i < n; i++)
	{
		std::cin >> tmp;
		coins.push_back(tmp);
		if (tmp <= k)
			dp[tmp] = 1;
	}
	
	std::sort(coins.begin(), coins.end());

	for (int i = 2; i <= k; i++)
	{
		for (auto num : coins)
		{
			if (num >= i)
				break;

			int cmp = i - num;
			if (dp[cmp] == MAX)
				continue;

			dp[i] = std::min(dp[i], 1 + dp[cmp]);
		}
	}

	if (dp[k] == MAX)
		std::cout << "-1";
	else
		std::cout << dp[k];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}