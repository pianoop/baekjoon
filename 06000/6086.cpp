//최대 유량
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
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
			if (tmp == 0)
				break;

			ans += tmp;
		}

		cout << ans;
	}


private:
	void init()
	{
		mCap.resize(mN, vi(mN));
		mFlow.resize(mN, vi(mN));
		mEdges.resize(mN);

		char a, b;
		int n, val;
		cin >> n;
		while(n--)
		{
			cin >> a >> b >> val;
			if (a > 'Z')
				a -= 71;
			else
				a -= 65;
			if (b > 'Z')
				b -= 71;
			else
				b -= 65;

			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
			mCap[a][b] += val;
			mCap[b][a] += val;
		}
	}

	int bfs()
	{
		bool brFlag = false;

		vi Trace(mN, -1);
		queue<int> box;
		box.push(mS);

		while (!box.empty())
		{
			int now = box.front();
			box.pop();

			for (auto next : mEdges[now])
			{
				if (mCap[now][next] - mFlow[now][next] > 0 && Trace[next] < 0) {
					box.push(next);
					Trace[next] = now;

					if (next == mD)
					{
						brFlag = true;
						break;
					}
				}
			}

			if (brFlag)
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
	int mN = 52, mS = 0, mD = 25;

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