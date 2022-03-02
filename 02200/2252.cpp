//줄 세우기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void Input(vvi& edges, vi& indegree)
{
	int N, M;
	std::cin >> N >> M;
	edges.resize(N + 1);
	indegree.resize(N + 1);

	int a, b;
	while (M--)
	{
		std::cin >> a >> b;
		edges[a].push_back(b);
		indegree[b]++;
	}

}

void Sort(vvi& edges, vi& indegree)
{
	int n = int(indegree.size() - 1);
	std::queue<int> BFSbox;

	for (int i = 1;i <= n;i++)
	{
		if (indegree[i] == 0)
		{
			BFSbox.push(i);
			printf("%d ", i);
		}
	}

	while (!BFSbox.empty())
	{
		for (auto& under : edges[BFSbox.front()])
		{
			if (--indegree[under] == 0)
			{
				BFSbox.push(under);
				printf("%d ", under);
			}
		}
		BFSbox.pop();
	}

}

void Solve()
{
	vi indegree;
	vvi edges;
	Input(edges, indegree);
	Sort(edges, indegree);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}