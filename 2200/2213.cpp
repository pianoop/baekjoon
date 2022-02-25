//트리의 독립집합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

std::array<vi, 2> DFS(const int now, const int prev, vi* DP, const vvi& edges, const vi& cost)
{
	std::array<vi, 2> ansbox;
	ansbox[1].push_back(now);
	DP[1][now] = cost[now];
	if (now != 1 && int(edges[now].size()) == 1)
		return ansbox;

	std::array<vi, 2> temp;
	for (auto& a : edges[now])
	{
		if (a != prev)
		{
			if (DP[1][a] == 0)
				temp=DFS(a, now, DP, edges, cost);

			DP[1][now] += DP[0][a];
			ansbox[1].insert(ansbox[1].end(), temp[0].begin(), temp[0].end());
			if (DP[1][a] > DP[0][a])
			{
				DP[0][now] += DP[1][a];
				ansbox[0].insert(ansbox[0].end(), temp[1].begin(), temp[1].end());
			}
			else
			{
				DP[0][now] += DP[0][a];
				ansbox[0].insert(ansbox[0].end(), temp[0].begin(), temp[0].end());
			}

		}
	}

	return ansbox;
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
	std::array<vi, 2> indepset;
	DP[0].resize(N + 1), DP[1].resize(N + 1);

	indepset=DFS(1, 0, DP, edges, cost);

	int ans,i=0;
	if (DP[1][1] > DP[0][1])
	{
		ans = DP[1][1];
		i = 1;
	}
	else
		ans = DP[0][1];

	std::cout << ans << "\n";

	std::sort(indepset[i].begin(), indepset[i].end());
	for (auto& a : indepset[i])
		std::cout << a << " ";

	return 0;
}