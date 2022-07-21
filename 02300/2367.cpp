//파티
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INTMAX = 0x7FFFFFFF;

class Pos
{
public:
	int x, y;

	bool operator==(Pos& Other)
	{
		return x == Other.x && y == Other.y;
	}
};
typedef vector<Pos> vP;

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
		int n, k, d;
		cin >> n >> k >> d;
		mN = n + d + 2;
		mS = 0;
		mD = mN - 1;

		mEdges.resize(mN);
		mCap.resize(mN, vi(mN));
		mFlow.resize(mN, vi(mN));

		int tmp, end = n + d;
		for (int i = n + 1; i <= end; i++)
		{
			cin >> tmp;
			mEdges[i].push_back(mD);
			mCap[i][mD] = tmp;
		}

		for (int i = 1; i <= n; i++)
		{
			mEdges[0].push_back(i);
			mEdges[i].push_back(0);
			mCap[0][i] = k;

			cin >> tmp;
			int tmp2;
			while (tmp--)
			{
				cin >> tmp2;
				tmp2 += n;
				mEdges[i].push_back(tmp2);
				mEdges[tmp2].push_back(i);
				mCap[i][tmp2] = 1;
			}
		}
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