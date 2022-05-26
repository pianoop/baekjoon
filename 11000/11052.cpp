//카드 구매하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;


void Solve()
{
	int N;
	std::cin >> N;
	
	int cost;
	vi dp(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> cost;
		int j = 0;
		for (int k = i; k <= N; j++,k++)
			dp[k] = std::max(dp[k], dp[j] + cost);
	}

	std::cout << dp[N];

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}