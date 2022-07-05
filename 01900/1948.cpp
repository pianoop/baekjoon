//임계경로
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		cout << bfs() << "\n" << trace_cnt();	
	}


private:
	void input()
	{
		int e;
		cin >> mN >> e;
		mEdges.resize(mN + 1);
		mEdges2.resize(mN + 1);
		mDp.resize(mN + 1, -1);

		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mEdges2[b].push_back({ a, cost });
		}

		cin >> mS >> mF;
	}

	int bfs()
	{
		queue<pii> box;
		box.push({ mS, 0 });
		mDp[mS] = 0;

		while (!box.empty())
		{
			auto [now, cost] = box.front();
			box.pop();

			int& nowDp = mDp[now];
			if (nowDp > cost)
				continue;

			for (auto [next, nextCost] : mEdges[now])
			{
				int sumCost = cost + nextCost;
				if (mDp[next] < sumCost)
				{
					mDp[next] = sumCost;
					box.push({ next, sumCost });
				}
			}
		}

		return mDp[mF];
	}

	int trace_cnt()
	{
		vi check(mN + 1, -1);
		int cnt = 0;

		queue<int> box;
		box.push(mF);
		while(!box.empty())
		{
			int now = box.front();
			box.pop();

			for (auto [next, nextCost] : mEdges2[now])
			{
				if (mDp[next] + nextCost == mDp[now])
				{
					cnt++;

					if (check[next] < 0)
					{
						check[next] = 0;
						box.push(next);
					}
				}
			}
		}

		return cnt;
	}


private:
	vvpii mEdges, mEdges2;
	vi mDp;
	int mN, mS, mF;

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