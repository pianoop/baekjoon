//2xn 타일링 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n;
	std::cin >> n;

	const int Prime = 10007;
	vi DP(n + 1);
	DP[0] = DP[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] * 2)%Prime;
	}

	std::cout << DP[n];

	return 0;
}