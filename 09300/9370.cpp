//미확인 도착지
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{

		int E, X,s,g,h;
		std::cin >> V >> E >> X >> s >> g >> h;

		vvD graph(V + 1);
		for (int a, b, c, i = 0;i < E;i++)
		{
			std::cin >> a >> b >> c;
			graph[a].push_back(Dis(b, c));
			graph[b].push_back(Dis(a, c));
		}

		vi ans1(X), ans0;
		for (int i = 0;i < X;i++)
		{
			std::cin >> ans1[i];
		}

		
		vi sD=Dijkstra(s,graph), gD = Dijkstra(g, graph), hD = Dijkstra(h, graph);
		int gh = gD[h];
		for (int i = 0;i < X;i++)
		{
			if (sD[ans1[i]] - gh == (Min(sD[g] + hD[ans1[i]], sD[h] + gD[ans1[i]])))
				ans0.push_back(ans1[i]);
		}
		std::sort(ans0.begin(), ans0.end());
		for (auto& a : ans0)
			std::cout << a << " ";
		
		std::cout << "\n";
	}

	return 0;
}