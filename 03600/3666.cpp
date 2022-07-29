//리스크
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vvc;
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
		int flow, total, l = 0, r = mMid;

		while (l <= r)
		{
			mMid = (l + r) >> 1;

			for (auto& line : mFlow)
				for (auto& i : line)
					i = 0;
			for (auto now : mAdjEnemy)
				mCap[now][mD] = mMid;

			total = 0;
			while (dinic_bfs())
			{
				fill(mCheck.begin(), mCheck.end(), 0);
				while ((flow = dinic_dfs(mS, INTMAX)) >= 0)
					total += flow;
			}

			if (total < mConflictNum * mMid)
				r = mMid - 1;
			else
				l = mMid + 1;
		}

		cout << r << "\n";
	}


private:
	void init()
	{
		cin >> mN;
		mS = 0;
		mD = (mN << 1) + 1;
		mSize = mD + 1;
		mEdges.resize(mSize);
		mCap.resize(mSize, vi(mSize));
		mFlow.resize(mSize, vi(mSize));
		mCheck.resize(mSize);
		mLevel.resize(mSize);

		int tmp;
		vi ID(mN + 1), cap; // ID가 0이면 그냥 영토, -1이면 적의, -2이면 적과 인접한 영토
		cap.reserve(mN + 1);
		cap.push_back(0);
		for (int i = 1; i <= mN; i++)
		{
			cin >> tmp;
			cap.push_back(tmp);

			if (tmp == 0)
				ID[i] = -1;
			else
				mMid += tmp;
		}

		vvc adj(mN + 1, vc(mN + 1));
		for (int i = 1; i <= mN; i++)
			for (int j = 1; j <= mN; j++)
				cin >> adj[i][j];

		for (int i = 1; i <= mN; i++)
		{
			if (ID[i] == -1)
			{
				auto& now = adj[i];
				for (int j = 1; j <= mN; j++)
				{
					if (now[j] == 'Y' && ID[j] >= 0)
						ID[j] = -2;
				}
			}
		}

		for (int i = 1; i <= mN; i++)
		{
			if (ID[i] == -2)
				mAdjEnemy.push_back((i << 1) - 1);
		}
		mConflictNum = (int)mAdjEnemy.size();
		

		for (int i = 1; i <= mN; i++)
		{
			if (ID[i] == -1)
				continue;

			// now1 = 입, now2 = 출
			int now2 = (i << 1), now1 = now2 - 1;

			mEdges[mS].push_back(now1);
			mEdges[now1].push_back(mS);
			mEdges[now1].push_back(now2);
			mEdges[now2].push_back(now1);

			mCap[mS][now1] = cap[i] - 1;
			mCap[now1][now2] = cap[i];

			// 적진 인접 지역
			if (ID[i] < 0)
			{
				mEdges[now1].push_back(mD);

				mCap[mS][now1]++;
				// mCap[now1][mD] = 이분 탐색에서 정해진 값으로
			}

			auto& now = adj[i];
			for (int j = 1; j <= mN; j++)
			{
				if (ID[j] != -1 && now[j] == 'Y')
				{
					int next = (j << 1) - 1;
					mEdges[now2].push_back(next);
					mEdges[next].push_back(now2);
					mCap[now2][next] = INTMAX;
				}
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
		int end = (int)tmp.size(), nowLevel = mLevel[now];
		for (int& i = mCheck[now]; i < end; i++)
		{
			int next = tmp[i];
			if (mLevel[next] > nowLevel)
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

		return -1;
	}


private:
	vvi mEdges, mCap, mFlow;
	vi mCheck, mLevel, mAdjEnemy;
	int mN, mSize, mS, mD, mMid = 0, mConflictNum;
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