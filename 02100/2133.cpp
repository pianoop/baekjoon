//타일 채우기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;


void Solve()
{
	int n;
	std::cin >> n;

	vi dp(n + 1);
	dp[0] = 1;
	if(n>1)
		dp[2] = 3;
	
	for (int i = 4; i <= n; i += 2)
	{
		dp[i] = dp[i - 2] * 3;
		int j = i - 4;
		while (j >= 0)
		{
			dp[i] += dp[j] * 2;
			j -= 2;
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