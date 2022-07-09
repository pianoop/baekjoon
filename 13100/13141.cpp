//Ignition
//-------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;


const int INTMAX = 0x7FFFFFFF;

class Pair
{
public:
	int dest, cost;

	bool operator<(const Pair& Other) const
	{
		return cost > Other.cost;
	}

};
typedef vector<Pair> vp;
typedef vector<vp> vvp;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int ans = INTMAX;
		for (int i = 1; i < mN; i++)
			ans = min(ans, ignition(i));

		cout << (ans >> 1);
		if (ans & 1)
			cout << ".5";
		else
			cout << ".0";
	}


private:
	void input()
	{
		int e;
		cin >> mN >> e;
		mN++;
		mEdges.resize(mN);

		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mEdges[b].push_back({ a, cost });
		}
	}

	int ignition(int s)
	{
		int MAX = 0;
		
		vi dist(mN, INTMAX);
		dijkstra(dist, s);

		vi check(mN, -1);
		for (int v1 = 1; v1 < mN; v1++)
		{
			if (check[v1] < 0)
			{
				int dist1 = dist[v1];

				for (auto [v2, cost] : mEdges[v1])
				{
					if (check[v2] < 0)
					{
						int dist2 = dist[v2];
						if (abs(dist1 - dist2) < cost)
							MAX = max(MAX, dist1 + dist2 + cost);
						else
							MAX = max(MAX, max(dist1, dist2) << 1);
					}
				}

				check[v1] = 0;
			}
		}

		return MAX;
	}

	void dijkstra(vi& dist, int s)
	{
		dist[s] = 0;

		priority_queue<Pair> box;
		box.push({ s, 0 });

		while (!box.empty())
		{
			auto [now, cost] = box.top();
			box.pop();

			if (dist[now] < cost)
				continue;

			for (auto [next, nextCost] : mEdges[now])
			{
				nextCost += cost;

				if (nextCost < dist[next])
				{
					dist[next] = nextCost;
					box.push({ next,  nextCost});
				}
			}
		}
	}


private:
	vvp mEdges;
	int mN;

};


void Solve()
{
	Q q;
	q.Solve();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}