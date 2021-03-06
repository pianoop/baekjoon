//타임머신
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;

const int unfinded = 0x7FFFFFFF;
int V;

class Dis
{
public:
	ll length;
	int idx;

	Dis(int a, int b) :idx(a), length(b) {}
	~Dis() {}

	bool operator<(const Dis& A) const
	{
		return this->length > A.length;
	}
};
typedef std::vector<Dis> vD;
typedef std::vector<vD> vvD;

vl Bellman_Ford(const int& A, const vvD& graph)
{
	vl ans(V + 1, unfinded);
	ans[A] = 0;

	for (int i = 0;i < V;i++)
	{
		for (int nowV = 1;nowV <= V;nowV++)
		{
			ll cost = ans[nowV];
			if (cost == unfinded)
				continue;
			for (auto& nextV : graph[nowV])
			{
				ll nextC = nextV.length + cost;
				if (ans[nextV.idx] > nextC)
					ans[nextV.idx] = nextC;
			}
		}
	}

	for (int nowV = 1;nowV <= V;nowV++)
	{
		ll cost = ans[nowV];
		if (cost == unfinded)
			continue;
		for (auto& nextV : graph[nowV])
		{
			ll nextC = nextV.length + cost;
			if (ans[nextV.idx] > nextC)
			{
				ans[0] = 1;
				return ans;
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

	vvD graph1(V + 1);
	for (int a, b, c, i = 0;i < E;i++)
	{
		std::cin >> a >> b >> c;
		graph1[a].push_back(Dis(b, c));
	}
	
	vl ans = Bellman_Ford(1, graph1);
	
	if (ans[0] == 1)
		std::cout << "-1";
	else
	{
		for (int a, i = 2;i <= V;i++)
		{
			a = int(ans[i]);
			if (a == unfinded)
				std::cout << "-1\n";
			else
				std::cout << a << "\n";
		}
	}

	return 0;
}