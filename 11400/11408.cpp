//열혈강호 5
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INTMAX = 100'000'000;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int workCnt = 0, minCost = 0;

		while (true)
		{
			vi check(mSize, -1), dist(mSize, INTMAX), inQueue(mSize);
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
					int nextDist = dist[now] + mCost[now][next];
					if (mRem[now][next] > 0 && dist[next] > nextDist)
					{
						dist[next] = nextDist;
						check[next] = now;
						if (inQueue[next] >= 0)
						{
							box.push(next);
							inQueue[next] = -1;
						}
					}
				}
			}

			if (check[mD] == -1)
				break;

			workCnt++;
			int flow = INTMAX;
			for (int i = mD; i != mS; i = check[i])
				flow = min(flow, mRem[check[i]][i]);
			for (int i = mD; i != mS; i = check[i])
			{
				minCost += flow * mCost[check[i]][i];
				mRem[check[i]][i] -= flow;
				mRem[i][check[i]] += flow;
			}
		}


		cout << workCnt << "\n" << minCost;
	}


private:
	void init()
	{
		int n, m;
		cin >> n >> m;
		mS = 0;
		mD = n + m + 1;
		mSize = mD + 1;
		mEdges.resize(mSize);
		mRem.resize(mSize, vi(mSize));
		mCost.resize(mSize, vi(mSize));
		mCheck.resize(mSize);
		mLevel.resize(mSize);

		int w, work, cost;
		for (int i = 1; i <= n; i++)
		{
			mEdges[mS].push_back(i);
			mEdges[i].push_back(mS);
			mRem[mS][i] = 1;

			cin >> w;
			while (w--)
			{
				cin >> work >> cost;
				work += n;

				mEdges[i].push_back(work);
				mEdges[work].push_back(i);
				mCost[i][work] = cost;
				mCost[work][i] = -cost;
				mRem[i][work] = 1;
			}
		}

		for (int i = n + 1; i < mD; i++)
		{
			mEdges[i].push_back(mD);
			mEdges[mD].push_back(i);
			mRem[i][mD] = 1;
		}
	}


private:
	vvi mEdges, mRem, mCost;
	vi mCheck, mLevel;
	int mN, mSize, mS, mD, mTot = 0;
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