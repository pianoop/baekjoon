//도시 왕복하기 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;


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
		int e;
		cin >> mN >> e;
		mN++;
		mCap.resize(mN, vi(mN));
		mFlow.resize(mN, vi(mN));
		mEdges.resize(mN);

		int a, b;
		while (e--)
		{
			cin >> a >> b;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
			mCap[a][b] = 1;
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

		int flow = 1;
		for (int i = mD; i != mS; i = Trace[i]) {
			mFlow[Trace[i]][i] += flow;
			mFlow[i][Trace[i]] -= flow;
		}

		return flow;
	}


private:
	vvi mEdges, mCap, mFlow;
	int mN, mS = 1, mD = 2;

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