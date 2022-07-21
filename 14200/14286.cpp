//간선 끊어가기 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INTMAX = 0x7FFFFFFF;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int ans = 0;

		while (true)
		{
			int tmp = bfs();
			if (tmp < 0)
				break;

			ans += tmp;
		}

		cout << ans;
	}


private:
	void init()
	{
		int n, m;
		cin >> n >> m;
		mN = n + 1;

		mEdges.resize(mN);
		mCap.resize(mN, vi(mN));
		mFlow.resize(mN, vi(mN));

		int a, b, c;
		while (m--)
		{
			cin >> a >> b >> c;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
			mCap[a][b] = c;
			mCap[b][a] = c;
		}

		cin >> mS >> mD;
	}

	int bfs()
	{
		vi trace(mN, -1);

		queue<int> box;
		box.push(mS);

		while (!box.empty() && trace[mD] < 0)
		{
			int now = box.front();
			box.pop();

			for (auto next : mEdges[now])
			{
				if (trace[next] < 0 && mCap[now][next] - mFlow[now][next] > 0)
				{
					box.push(next);
					trace[next] = now;
				}
			}
		}

		if (trace[mD] < 0)
			return -1;

		int flow = INTMAX;

		for (int i = mD; i != mS; i = trace[i])
			flow = min(flow, mCap[trace[i]][i] - mFlow[trace[i]][i]);

		for (int i = mD; i != mS; i = trace[i])
		{
			mFlow[trace[i]][i] += flow;
			mFlow[i][trace[i]] -= flow;
		}

		return flow;
	}


private:
	vvi mEdges, mCap, mFlow;
	int mN, mS, mD;

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