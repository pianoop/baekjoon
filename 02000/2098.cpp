//외판원 순회
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;
const int Max = int(1e9);

int TSP(int n, const int& start, int prev, int bitcity, vvi& DP, const vvi& edges, const int& N)
{
	if (n == N)
	{
		if (edges[prev][start] == 0)
			return Max;
		else
			return edges[prev][start];
	}
	if (DP[prev][bitcity] != -1)
		return DP[prev][bitcity];

	DP[prev][bitcity] = Max;

	for (int i = 0;i < N;i++)
	{
		if (bitcity & (1 << i) || edges[prev][i] == 0)
			continue;
		int nextW = bitcity | 1 << i;
		DP[prev][bitcity] = std::min(DP[prev][bitcity], edges[prev][i] + TSP(n + 1, start,i, nextW, DP, edges, N));
	}

	return DP[prev][bitcity];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vvi edges(N, vi(N));
	for (auto& n : edges)
		for (auto& m : n)
			std::cin >> m;

	vvi DP(N,vi(1 << N, -1));
	std::cout << TSP(1,0,0,1,DP,edges,N);

	return 0;
}