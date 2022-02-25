//물대기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::tuple<int, int, int> tup;

int find(const int& a, vi& head)
{
	if (head[a] < 0)
		return a;

	return head[a] = find(head[a], head);
}

bool Merge_CheckGroup(int a, int b, vi& head)
{
	a = find(a, head), b = find(b, head);
	if (a == b)
		return 0;

	if (a < b)
	{
		head[a] += head[b];
		head[b] = a;
	}
	else
	{
		head[b] += head[a];
		head[a] = b;
	}
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int N;
	std::cin >> N;

	std::vector<tup> graph;
	graph.reserve(N * N);
	for (int cost, i = 1;i < N + 1;i++)
	{
		std::cin >> cost;
		graph.push_back({ cost,0,i });
	}

	for (int cost,i = 1;i < N + 1;i++)
	{
		int j = 1;
		for (;j < i + 1;j++)
			std::cin >> cost;
		for (;j < N + 1;j++)
		{
			std::cin >> cost;
			graph.push_back({ cost,i,j });
		}
	}
	std::sort(graph.begin(), graph.end());

	int total = 0;
	vi head(N + 1,-1);
	N++;
	for (int i = 0;i<int(graph.size());i++)
	{
		int cost, a, b;
		std::tie(cost, a, b) = graph[i];
		if (Merge_CheckGroup(a, b, head))
		{
			total += cost;
			if (head[0] == -N)
				break;
		}
	}

	std::cout << total;

	return 0;
}