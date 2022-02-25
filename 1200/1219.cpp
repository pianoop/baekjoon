//오민식의 고민
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;

const ll unfinded = 100000000000000;
int V;

class Dis
{
public:
	int idx;
	ll length;

	Dis(int a, int b) :idx(a), length(b) {}
	~Dis() {}
};
typedef std::vector<Dis> vD;
typedef std::vector<vD> vvD;



vl Bellman_Ford(const int& A, const vvD& graph1)
{
	vl ans(V, unfinded);
	ans[A] = 0;

	for (int i = 0;i < V;i++)
	{
		for (int nowV = 0;nowV < V;nowV++)
		{
			ll cost = ans[nowV];
			if (cost == unfinded)
				continue;
			for (auto& nextV : graph1[nowV])
			{
				ll nextC = nextV.length + cost;
				if (ans[nextV.idx] > nextC)
					ans[nextV.idx] = nextC;
			}
		}
	}

	return ans;
}

void DFS(const int& S, const vvi& graph, vi& check)
{
	for (auto& a : graph[S])
	{
		if (check[a] == 0)
		{
			check[a] = 1;
			DFS(a, graph, check);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int S, F, E;
	std::cin >> V >> S >> F >> E;

	vvD graph1(V);
	vvi graph2(V);
	for (int a, b, c, i = 0;i < E;i++)
	{
		std::cin >> a >> b >> c;
		graph1[a].push_back(Dis(b, c));
		graph2[b].push_back(a);
	}

	vi earn(V);
	for (int i = 0;i < V;i++)
	{
		std::cin >> earn[i];
	}

	for (int i = 0;i < V;i++)
	{
		for (auto& a : graph1[i])
			a.length -= earn[a.idx];
	
	}


	vl ans1 = Bellman_Ford(S, graph1);

	if (ans1[F] == unfinded)
		std::cout << "gg";
	else
	{
		vi check(V);
		DFS(F, graph2, check);
        
		bool endflag = 0;
		for (int nowV = 0;nowV < V;nowV++)
		{
			ll cost = ans1[nowV];
			if (cost == unfinded)
				continue;
			for (auto& nextV : graph1[nowV])
			{
				ll nextCost = nextV.length + cost;
				if (ans1[nextV.idx] > nextCost && check[nowV] == 1)
				{
					endflag = 1;
					break;
				}
			}
			if (endflag)
				break;
		}
		if (endflag)
			std::cout << "Gee";
		else
			std::cout << -ans1[F] + earn[S];
	}
	return 0;
}