//할 일 정하기 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int solve(int n, int bitW, vi& DP, const vvi& cost, const int& N)
{
	if (n == N)
		return 0;
	if (DP[bitW] != 1000000)
		return DP[bitW];

	for (int i = 0;i < N;i++)
	{
		if (bitW & (1 << i))
			continue;
		int nextW = bitW | 1 << i;
		DP[bitW] = std::min(DP[bitW], cost[n][i] + solve(n + 1, nextW, DP, cost, N));
	}

	return DP[bitW];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int bit = 0, N;
	std::cin >> N;

	vvi cost(N, vi(N));
	for (auto& n : cost)
		for (auto& m : n)
			std::cin >> m;

	vi DP(1 << N, 1000000);
	int ans = solve(0, 0, DP, cost, N);

	std::cout << ans;

	return 0;
}