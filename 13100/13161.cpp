//
//
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

		while (dinic_bfs())
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			int flow = dinic_dfs(mS, INTMAX);
			while (flow != 0)
			{
				ans += flow;
				flow = dinic_dfs(mS, INTMAX);
			}
		}

		cout << ans << "\n";

		vi visit(mN);
		visit[mS] = -1;
		queue<int> box;
		box.push(mS);

		while (!box.empty())
		{
			int now = box.front();
			box.pop();

			for (auto next : mEdges[now])
			{
				if (visit[next] >= 0 && mCap[now][next] - mFlow[now][next] > 0)
				{
					visit[next] = -1;
					box.push(next);
				}
			}
		}

		for (int i = 1; i < mD; i++)
		{
			if (visit[i] < 0)
				cout << i << " ";
		}
		cout << "\n";
		for (int i = 1; i < mD; i++)
		{
			if (visit[i] >= 0)
				cout << i << " ";
		}
		cout << "\n";

	}


private:
	void init()
	{
		cin >> mN;
		mS = 0;
		mD = mN + 1;
		mN += 2;
		mEdges.resize(mN);
		mCap.resize(mN, vi(mN));
		mFlow.resize(mN, vi(mN));
		mCheck.resize(mN);
		mLevel.resize(mN);

		int tmp;
		for (int i = 1; i < mD; i++)
		{
			cin >> tmp;

			if (tmp == 1)
			{
				mEdges[mS].push_back(i);
				mEdges[i].push_back(mS);
				mCap[mS][i] = INTMAX;
			}
			else if (tmp == 2)
			{
				mEdges[i].push_back(mD);
				mCap[i][mD] = INTMAX;
			}
		}

		for (int i = 1; i < mD; i++)
		{
			for (int j = 1; j < i; j++)
			{
				cin >> mCap[i][j];
				mEdges[i].push_back(j);

			}
			cin >> tmp; // (i, i) = 0 처리
			for (int j = i + 1; j < mD; j++)
			{
				cin >> mCap[i][j];
				mEdges[i].push_back(j);
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
	int mN, mS, mD;
	bool mbException;

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