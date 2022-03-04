//ACM Craft
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void Input(const int& N, vvi& edges, vi& indegree, vi& cost)
{
	int M;
	std::cin >> M;

	std::for_each(cost.begin() + 1, cost.end(), [](auto& c)
		{
			std::cin >> c;
		});

	while (M--)
	{
		int a, b;
		std::cin >> a >> b;
		indegree[b]++;
		edges[a].push_back(b);
	}
}

int Sort(const int& N, vvi& edges, vi& indegree, vi& cost)
{
	int build_win;
	std::cin >> build_win;

	vi DP(N + 1);
	std::priority_queue<int, vi, std::greater<>> BFSbox;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			BFSbox.push(i);
		}
	}

	while (!BFSbox.empty())
	{
		int now = BFSbox.top();
		BFSbox.pop();

		DP[now] += cost[now];
		if (now == build_win)
			break;

		for (auto& under : edges[now])
		{
			if (DP[now] > DP[under])
				DP[under] = DP[now];

			if (--indegree[under] == 0)
			{
				BFSbox.push(under);
			}
		}
	}

	return DP[build_win];
}

void Solve()
{
	int N;
	std::cin >> N;
	vi indegree(N + 1), cost(N + 1);
	vvi edges(N + 1);
	Input(N, edges, indegree, cost);
	printf("%d\n",Sort(N, edges, indegree, cost));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
		Solve();

	return 0;
}