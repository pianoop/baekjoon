//동전 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, endpoint;
	std::cin >> N >> endpoint;
	
	vi coin(N);
	for (auto& a : coin)
		std::cin >> a;

	vi dp(endpoint+1);
	dp[0] = 1;

	for (int i = 0;i < N;i++)
	{
		for (int now = coin[i];now <= endpoint;now++)
		{
			dp[now] += dp[now - coin[i]];
		}
	}

	std::cout << dp[endpoint];

	return 0;
}