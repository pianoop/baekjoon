//특정한 최단 경로
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
class Dis;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<Dis> vD;
typedef std::vector<vD> vvD;

const int unfinded = 9999999;
int V;

class Dis
{
public:
	int length, idx;

	Dis(int a, int b) :idx(a), length(b) {}
	~Dis() {}

	bool operator<(const Dis& A) const
	{
		return this->length > A.length;
	}
};

vi Dijkstra(const int& A, const vvD& graph)
{
	vi ans(V + 1, unfinded);
	ans[A] = 0;
	std::priority_queue<Dis> Box;
	Box.push(Dis(A, 0));

	while (!Box.empty())
	{
		int cost = Box.top().length, nowV = Box.top().idx;
		Box.pop();

		if (cost > ans[nowV])
			continue;

		for (int nextC, nextV, i = 0;i < (int)graph[nowV].size();i++)
		{
			nextV = graph[nowV][i].idx, nextC = graph[nowV][i].length + cost;

			if (ans[nextV] > nextC)
			{
				ans[nextV] = nextC;
				Box.push(Dis(nextV, nextC));
			}
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int E;
	std::cin >> V >> E;

	vvD graph(V + 1);
	for (int a, b, c, i = 0;i < E;i++)
	{
		std::cin >> a >> b >> c;
		graph[a].push_back(Dis(b, c));
		graph[b].push_back(Dis(a, c));
	}
	int A, B;
	std::cin >> A >> B;

	int one, two;
	vi ans = Dijkstra(1, graph);
	one = ans[A], two = ans[B];
	ans = Dijkstra(A, graph);
	one += ans[B], two += ans[V];
	ans = Dijkstra(B, graph);
	one += ans[V], two += ans[A];

	int Min = (one < two ? one : two);
	if (Min >= unfinded)
		Min = -1;
	std::cout << Min;

	return 0;
}