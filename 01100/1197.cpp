//최소 스패닝 트리
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::tuple<int, int, int> ti;
typedef std::vector<ti> vti;

int find(const int& a, vi& head)
{
	if (head[a] < 0)
		return a;

	return head[a] = find(head[a], head);
}

bool Merge_CheckGroup(const int& a, const int& b, vi& head)
{
	int head_a = find(a, head), head_b = find(b, head);
	if (head_a == head_b)
		return 0;

	head[head_a] += head[head_b];
	head[head_b] = head_a;
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int V, E;
	std::cin >> V >> E;

	vti graph(E);
	vi head(V + 1, -1);
	for (auto& [cost, a, b] : graph)
	{
		std::cin >> a >> b >> cost;
	}

	std::sort(graph.begin(), graph.end());

	int cnt = 1, Mincost=0;
	for(auto& [cost,a,b]:graph)
	{
		if (Merge_CheckGroup(a, b, head))
		{
			cnt++;
			Mincost += cost;
			if (cnt == V)
				break;
		}
	}

	std::cout << Mincost;

	return 0;
}