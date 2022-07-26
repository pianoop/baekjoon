//행렬만들기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<char> vc;
typedef vector<vc> vvc;
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
		if (mbEx)
		{
			cout << -1;
			return;
		}

		int flow, total = 0;
		while (dinic_bfs())
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			while ((flow = dinic_dfs(mS, INTMAX)) != 0)
				total += flow;
		}

		if (mTot != total)
		{
			cout << -1;
			return;
		}
		else
			cout << 1 << "\n";


		for (int i = 1; i <= mN; i++)
		{
			for (int j = mN + 1; j < mD; j++)
			{
				if (mFlow[i][j] == 0)
					cout << 0;
				else
					cout << 1;
			}
			cout << "\n";
		}

	}


private:
	void init()
	{
		cin >> mN;
		mS = 0;
		mD = mN * 2 + 1;
		mSize = mD + 1;
		
		mEdges.resize(mSize);
		mCap.resize(mSize, vi(mSize));
		mFlow.resize(mSize, vi(mSize));
		mCheck.resize(mSize);
		mLevel.resize(mSize);

		vi row(mN + 1), col(mN + 1);
		int tot1 = 0, tot2 = 0;
		for (int i = 1; i <= mN; i++)
		{
			cin >> row[i];
			tot1 += row[i];
		}
		for (int i = 1; i <= mN; i++)
		{
			cin >> col[i];
			tot2 += col[i];
		}

		if (mbEx = (tot1 != tot2))
			return;

		mTot = tot1;

		for (int i = 1; i <= mN; i++)
		{
			mEdges[mS].push_back(i);
			mEdges[i].push_back(mS);
			mCap[mS][i] = row[i];

			for (int j = mN + 1; j < mD; j++)
			{
				mEdges[i].push_back(j);
				mEdges[j].push_back(i);
				mCap[i][j] = 1;
			}
		}
		
		for (int i = mN + 1; i < mD; i++)
		{
			mEdges[i].push_back(mD);
			mEdges[mD].push_back(i);
			mCap[i][mD] = col[i - mN];
		}


	}

	bool dinic_bfs()
	{
		fill(mLevel.begin(), mLevel.end(), -1);
		mLevel[mS] = 0;

		queue<int> box;
		box.push(mS);

		while (!box.empty() && mLevel[mD] < 0)
		{
			int now = box.front();
			box.pop();

			int nextLevel = mLevel[now] + 1;
			for (auto next : mEdges[now])
			{
				if (mLevel[next] < 0 && mCap[now][next] - mFlow[now][next] > 0)
				{
					box.push(next);
					mLevel[next] = nextLevel;
				}
			}
		}

		return !(mLevel[mD] < 0);
	}

	int dinic_dfs(int now, int nowFlow)
	{
		if (now == mD)
			return nowFlow;

		auto& tmp = mEdges[now];
		int end = (int)tmp.size(), nextLevel = mLevel[now] + 1;
		for (int& i = mCheck[now]; i < end; i++)
		{
			int next = tmp[i];
			if (mLevel[next] == nextLevel)
			{
				int f = mCap[now][next] - mFlow[now][next];
				if (f > 0)
				{
					int flow = dinic_dfs(next, min(nowFlow, f));
					if (flow > 0)
					{
						mFlow[now][next] += flow;
						mFlow[next][now] -= flow;
						return flow;
					}
				}
			}
		}

		return 0;
	}


private:
	vvi mEdges, mCap, mFlow;
	vi mCheck, mLevel;
	int mN, mSize, mS, mD, mTot = 0;
	bool mbEx = false;
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