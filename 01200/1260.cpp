//DFS와 BFS
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef std::vector<int> vi;

void DFS(int now, const std::vector<vi>& graph, vi& check)
{
	check[now] = 1;
	std::cout << now << " ";
	for (auto a:graph[now])
	{
		if (check[a]==0)
			DFS(a, graph, check);
	}
}

void BFS(int now, const std::vector<vi>& graph, vi& check)
{
	std::cout << now << " ";
	check[now] = 1;
	std::queue<int> box;
	box.push(now);
	while (!box.empty())
	{
		int cur = box.front();
		box.pop();
		for (auto a : graph[cur])
		{
			if (check[a] == 0)
			{
				box.push(a);
				std::cout << a << " ";
				check[a] = 1;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M, V;
	std::cin >> N >> M >> V;

	std::vector<vi> graph(N + 1);
	for (int x, y, i = 0;i < M;i++)
	{
		std::cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0;i < (int)graph.size();i++)
		std::sort(graph[i].begin(), graph[i].end());
	{
		vi checkd(N + 1);
		DFS(V, graph, checkd);
	}
	std::cout << "\n";
	{
		vi checkb(N + 1);
		BFS(V, graph, checkb);
	}

	return 0;
}