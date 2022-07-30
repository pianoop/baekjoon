//격자 0 만들기
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
		int total = 0, flow;
		while (dinic_bfs())
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			while ((flow = dinic_dfs(mS, INTMAX)) >= 0)
				total += flow;
		}

		cout << mTot - total << "\n";
	}


private:
	void init()
	{
		int n, m;
		cin >> n >> m;
		mS = 0;
		mD = n * m + 1;
		mSize = mD + 1;
		mEdges.resize(mSize);
		mRem.resize(mSize, vi(mSize));
		mCheck.resize(mSize);
		mLevel.resize(mSize);

		int idx = 1, tmp;
		for (int i = 0; i < n; i++)
		{
			if (i & 1)
			{
				for (int j = 0; j < m; j++)
				{
					cin >> tmp;
					mTot += tmp;
					if (j & 1)
					{
						mEdges[mS].push_back(idx);
						mEdges[idx].push_back(mS);
						mRem[mS][idx++] = tmp;
					}
					else
					{
						mEdges[idx].push_back(mD);
						mRem[idx++][mD] = tmp;
					}
				}
			}
			else
			{
				for (int j = 0; j < m; j++)
				{
					cin >> tmp;
					mTot += tmp;
					if (j & 1)
					{
						mEdges[idx].push_back(mD);
						mRem[idx++][mD] = tmp;
					}
					else
					{
						mEdges[mS].push_back(idx);
						mEdges[idx].push_back(mS);
						mRem[mS][idx++] = tmp;
					}
				}
			}
		}

		int next;
		idx = 1;
		for (int i = 1; i < n; i++)
		{
			if (i & 1)
			{
				for (int j = 1; j < m; j++, idx++)
				{
					next = idx + 1;
					mEdges[idx].push_back(next);
					mEdges[next].push_back(idx);
					if (j & 1)
					{
						mRem[idx][next] = INTMAX;

						next = idx + m;
						mEdges[idx].push_back(next);
						mEdges[next].push_back(idx);
						mRem[idx][next] = INTMAX;
					}
					else
					{
						mRem[next][idx] = INTMAX;

						next = idx + m;
						mEdges[idx].push_back(next);
						mEdges[next].push_back(idx);
						mRem[next][idx] = INTMAX;
					}
				}

				idx++;
			}
			else
			{
				for (int j = 1; j < m; j++, idx++)
				{
					next = idx + 1;
					mEdges[idx].push_back(next);
					mEdges[next].push_back(idx);
					if (j & 1)
					{
						mRem[next][idx] = INTMAX;

						next = idx + m;
						mEdges[idx].push_back(next);
						mEdges[next].push_back(idx);
						mRem[next][idx] = INTMAX;
					}
					else
					{
						mRem[idx][next] = INTMAX;

						next = idx + m;
						mEdges[idx].push_back(next);
						mEdges[next].push_back(idx);
						mRem[idx][next] = INTMAX;
					}
				}

				idx++;
			}
		}

		if (n & 1)
		{
			for (int j = 1; j < m; j++, idx++)
			{
				next = idx + 1;
				mEdges[idx].push_back(next);
				mEdges[next].push_back(idx);
				if (j & 1)
					mRem[idx][next] = INTMAX;
				else
					mRem[next][idx] = INTMAX;
			}
		}
		else
		{
			for (int j = 1; j < m; j++, idx++)
			{
				next = idx + 1;
				mEdges[idx].push_back(next);
				mEdges[next].push_back(idx);
				if (j & 1)
					mRem[next][idx] = INTMAX;
				else
					mRem[idx][next] = INTMAX;
			}
		}

		idx = m;
		if (m & 1)
		{
			for (int i = 1; i < n; i++, idx += m)
			{
				next = idx + m;
				mEdges[idx].push_back(next);
				mEdges[next].push_back(idx);
				if (i & 1)
					mRem[idx][next] = INTMAX;
				else
					mRem[next][idx] = INTMAX;
			}
		}
		else
		{
			for (int i = 1; i < n; i++, idx += m)
			{
				next = idx + m;
				mEdges[idx].push_back(next);
				mEdges[next].push_back(idx);
				if (i & 1)
					mRem[next][idx] = INTMAX;
				else
					mRem[idx][next] = INTMAX;
			}
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
				if (mLevel[next] < 0 && mRem[now][next] > 0)
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
		int end = (int)tmp.size(), nowLevel = mLevel[now];
		for (int& i = mCheck[now]; i < end; i++)
		{
			int next = tmp[i];
			if (mLevel[next] > nowLevel)
			{
				int f = mRem[now][next];
				if (f > 0)
				{
					int flow = dinic_dfs(next, min(nowFlow, f));
					if (flow > 0)
					{
						mRem[now][next] -= flow;
						mRem[next][now] += flow;
						return flow;
					}
				}
			}
		}

		return -1;
	}


private:
	vvi mEdges, mRem;
	vi mCheck, mLevel;
	int mN, mSize, mS, mD, mTot = 0;
};


void Solve()
{
	int T;
	cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}