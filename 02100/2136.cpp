//도시 왕복하기 2
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
			if (tmp == 0)
				break;

			ans += tmp;
		}

		cout << ans;
	}


private:
	void init()
	{
		int n, p;
		cin >> n >> p;
		mN = (n << 1) + 1;
		mS = n + 1;
		mD = 2;

		mEdges.resize(mN);
		mCap.resize(mN, vi(mN));
		mFlow.resize(mN, vi(mN));

		int a, b, an, bn;
		while (p--)
		{
			cin >> a >> b;

			an = a + n, bn = b + n;
			mEdges[an].push_back(b);
			mEdges[b].push_back(an);
			mEdges[bn].push_back(a);
			mEdges[a].push_back(bn);

			mCap[an][b] = mCap[bn][a] = 1;
		}

		for (int i = 3, ni = 3 + n; i <= n; i++, ni++)
		{
			mEdges[i].push_back(ni);
			mEdges[ni].push_back(i);
			mCap[i][ni] = 1;
		}
	}

	int bfs()
	{
		bool bEndFlag = false;

		vi Trace(mN, -1);
		queue<int> box;
		box.push(mS);

		while (!box.empty())
		{
			int now = box.front();
			box.pop();

			for (auto next : mEdges[now])
			{
				if (Trace[next] < 0 && mCap[now][next] - mFlow[now][next] > 0)
				{
					box.push(next);
					Trace[next] = now;

					if (next == mD)
					{
						bEndFlag = true;
						break;
					}
				}
			}

			if (bEndFlag)
				break;
		}

		if (Trace[mD] < 0)
			return 0;

		int flow = INTMAX;
		for (int i = mD; i != mS; i = Trace[i])
			flow = min(flow, mCap[Trace[i]][i] - mFlow[Trace[i]][i]);
		for (int i = mD; i != mS; i = Trace[i])
		{
			mFlow[Trace[i]][i] += flow;
			mFlow[i][Trace[i]] -= flow;
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