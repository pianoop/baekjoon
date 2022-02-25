//웜홀
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;

const int unfinded = 100000000;
int V;

class Dis
{
public:
	int idx;
	int length;

	Dis(int a, int b) :idx(a), length(b) {}
	~Dis() {}
};
typedef std::vector<Dis> vD;
typedef std::vector<vD> vvD;



bool Bellman_Ford(const int& A, const vvD& graph1)
{
	vi ans(V+1, unfinded);
	ans[A] = 0;
	for (int i = 1;i < V+1;i++)
	{
		for (int nowV = 1;nowV < V+1;nowV++)
		{
			int cost = ans[nowV];
			for (auto& nextV : graph1[nowV])
			{
				int nextC = nextV.length + cost;
				if (ans[nextV.idx] > nextC)
					ans[nextV.idx] = nextC;
			}
		}
	}

	for (int nowV = 1;nowV <= V;nowV++)
	{
		int cost = ans[nowV];
		if (cost == unfinded)
			continue;
		for (auto& nextV : graph1[nowV])
		{
			int nextC = nextV.length + cost;
			if (ans[nextV.idx] > nextC)
			{
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{

		int E, W;
		std::cin >> V >> E >> W;

		vvD graph1(V+1);
		for (int a, b, c, i = 0;i < E;i++)
		{
			std::cin >> a >> b >> c;
			graph1[a].push_back(Dis(b, c));
			graph1[b].push_back(Dis(a, c));
		}
		for (int a, b, c, i = 0;i < W;i++)
		{
			std::cin >> a >> b >> c;
			graph1[a].push_back(Dis(b, -c));
		}

		vi check(V + 1);

		if (Bellman_Ford(1,graph1))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";

	}
	return 0;
}