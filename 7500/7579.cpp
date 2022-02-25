//앱
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M, total = 0;
	std::cin >> N >> M;

	vi A(N);
	for (auto& a : A)
		std::cin >> a;

	vi C(N);
	for (auto& c : C)
	{
		std::cin >> c;
		total += c;
	}

	vi dp(total + 1,0);

	for (int n = 0;n < N;n++)
	{
		for (int i = total;i >= C[n];i--)
		{
			dp[i] = Max(dp[i], dp[i - C[n]] + A[n]);
		}
	}
	int ans = 0;
	for (int i = 0;i <= total;i++)
	{
		if (dp[i] >= M)
		{
			ans = i;
			break;
		}
	}

	std::cout << ans;
	
	return 0;
}