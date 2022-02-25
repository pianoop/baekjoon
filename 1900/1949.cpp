//우수 마을
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

void DFS(const int now, const int prev,  vi* DP, const vvi& edges, const vi& cost)
{
	DP[1][now] = cost[now];
	if (now != 1 && int(edges[now].size()) == 1)
		return;
	
	for (auto& a : edges[now])
	{
		if (a != prev)
		{
			if (DP[1][a] == 0)
				DFS(a, now, DP, edges, cost);

			DP[1][now] += DP[0][a];
			DP[0][now] += Max(DP[0][a], DP[1][a]);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vi cost(N + 1);
	std::for_each(cost.begin() + 1, cost.end(), [&cost](auto& a)
		{
			std::cin >> a;
		});

	vvi edges(N + 1);
	for (int i = 1;i < N;i++)
	{
		int a, b;
		std::cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vi DP[2];
	DP[0].resize(N + 1), DP[1].resize(N + 1);

	DFS(1, 0, DP, edges,cost);
	
	std::cout << (DP[0][1]>DP[1][1]? DP[0][1] : DP[1][1]);

	return 0;
}