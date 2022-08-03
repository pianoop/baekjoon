//책 구매하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INTMAX = 100'000'000;

struct Edge
{
	int to, rem, cost;
	Edge* rev = nullptr;

	Edge(int t, int r, int c) :to(t), rem(r), cost(c) {}

	void Push(int flow)
	{
		rem -= flow;
		rev->rem += flow;
	}
};
typedef vector<Edge*> vD;

class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int maxCost = 0;

		while (true)
		{
			vi prev(mSize, -1), dist(mSize, INTMAX), inQueue(mSize);
			vD idxPrev(mSize);
			dist[mS] = 0, inQueue[mS] = -1;

			queue<int> box;
			box.push(mS);

			while (!box.empty())
			{
				int now = box.front();
				box.pop();

				inQueue[now] = 0;
				for (auto& next : mEdges[now])
				{
					int nextDist = dist[now] + next->cost;
					if (next->rem > 0 && dist[next->to] > nextDist)
					{
						dist[next->to] = nextDist;
						prev[next->to] = now;
						idxPrev[next->to] = next;
						if (inQueue[next->to] >= 0)
						{
							box.push(next->to);
							inQueue[next->to] = -1;
						}
					}
				}
			}

			if (prev[mD] == -1)
				break;

			int flow = INTMAX;
			for (int i = mD; i != mS; i = prev[i])
				flow = min(flow, idxPrev[i]->rem);
			for (int i = mD; i != mS; i = prev[i])
			{
				maxCost += flow * idxPrev[i]->cost;
				idxPrev[i]->Push(flow);
			}
		}

		cout << maxCost;
	}


private:
	void init()
	{
		int n, m, mid;
		cin >> n >> m;
		mS = 0;
		mid = m + 1;
		mD = n + m + 1;
		mSize = mD + 1;
		mEdges.resize(mSize);
		mCheck.resize(mSize);
		mLevel.resize(mSize);

		int tmp;
		for (int i = mid; i < mD; i++)
		{
			cin >> tmp;
			connect(i, mD, tmp);
		}
		for (int i = 1; i < mid; i++)
		{
			cin >> tmp;
			connect(mS, i, tmp);
		}

		for (int i = 1; i < mid; i++)
		{
			for (int j = mid; j < mD; j++)
			{
				cin >> tmp;
				connect(i, j, INTMAX, tmp);
			}
		}

	}

	void connect(int u, int v, int cap, int cost = 0)
	{
		Edge *uv = new Edge(v, cap, cost)
			, *vu = new Edge(u, 0, -cost);
		uv->rev = vu;
		vu->rev = uv;
		mEdges[u].push_back(uv);
		mEdges[v].push_back(vu);
	}

private:
	vector<vD> mEdges;
	vi mCheck, mLevel;
	int mN, mSize, mS, mD;
};


void Solve()
{
	Q q;
	q.Solve();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}