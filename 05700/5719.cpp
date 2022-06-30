//거의 최단 경로
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INTMAX = 0x7FFFFFFF;

struct Edge
{
	int cost, dest;

	bool operator<(auto& other) const
	{
		return cost > other.cost;
	}
};

class Q
{
public:
	Q(int n, int e) :mN(n)
	{
		input(e);
	}

	void Solve(int s, int d)
	{
		vi dist(mN, INTMAX);
		dijkstra(dist, s);

		if (dist[d] != INTMAX)
		{
			trace(dist, s, d);

			reset(dist);
			dijkstra(dist, s);
		}


		if (dist[d] == INTMAX)
			cout << -1 << "\n";
		else
			cout << dist[d] << "\n";
	}


private:
	void input(int e)
	{
		mEdges.resize(mN, vi(mN, -1));
		mEdges2.resize(mN, vi(mN, -1));

		int s, d, c;
		while (e--)
		{
			cin >> s >> d >> c;
			mEdges[s][d] = c;
			mEdges2[d][s] = c;
		}
	}

	void dijkstra(vi& dist, int source)
	{
		dist[source] = 0;
		priority_queue<Edge> box;
		box.push({ 0, source });

		while (!box.empty())
		{
			auto [cost, d] = box.top();
			box.pop();

			if (cost > dist[d])
				continue;

			auto& now = mEdges[d];
			int nextC;
			for (int i = 0; i < mN; i++)
			{
				if (now[i] < 0)
					continue;

				nextC = dist[d] + now[i];
				if (nextC < dist[i])
				{
					dist[i] = nextC;
					box.push({ nextC, i });
				}
			}
		}
	}

	void trace(vi& dist, int s, int d)
	{
		vi check(mN, -1);

		queue<int> box; // dist, dest 저장
		box.push(d);
		while (!box.empty())
		{
			int now = box.front();
			box.pop();

			if (check[now] >= 0 || now == s)
				continue;
			check[now] = 0;

			auto& tmp = mEdges2[now];
			for (int i = 0; i < mN; i++)
			{
				if (check[i] >= 0)
					continue;

				if (tmp[i] >= 0 && dist[now] == dist[i] + tmp[i])
				{
					mEdges[i][now] = -1;
					box.push(i);
				}
			}
		}
	}

	void reset(vi& dist)
	{
		for (auto& i : dist)
			i = INTMAX;
	}


private:
	vvi mEdges, mEdges2;
	int mN;

};


void Solve()
{
	int a, b, s, d;
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		cin >> s >> d;
		Q ans(a, b);
		ans.Solve(s, d);
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}