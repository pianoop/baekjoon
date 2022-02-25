//파티
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

	int E, X;
	std::cin >> V >> E >> X;

	vvD graph1(V + 1), graph2(V + 1);
	for (int a, b, c, i = 0;i < E;i++)
	{
		std::cin >> a >> b >> c;
		graph1[a].push_back(Dis(b, c));
		graph2[b].push_back(Dis(a, c));
	}

	vi a = Dijkstra(X, graph1);
	vi b = Dijkstra(X, graph2);

	int Max = 0;
	for (int t, i = 1;i < V + 1;i++)
	{
		t = a[i] + b[i];
		if (Max < t)
			Max = t;
	}

	std::cout << Max;

	return 0;
}