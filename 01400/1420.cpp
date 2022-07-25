//학교 가지마!
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
		if (mbException)
		{
			cout << -1;
			return;
		}

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

		cout << ans;
	}


private:
	void init()
	{
		int n, m, nm;
		cin >> n >> m;
		nm = n * m;
		mN = nm << 1;
		mEdges.resize(mN);
		mCheck.resize(mN);
		mLevel.resize(mN);

		vector<char> map(nm);
		for (auto& c : map)
			cin >> c;

		bool bPrev;
		int idx = 0, prev, kN = -1, kM = -1, hN = -1, hM = -1;
		for (int i = 0; i < n; i++)
		{
			bPrev = false;
			for (int j = 0; j < m; j++, idx++)
			{
				if (map[idx] == '#')
				{
					bPrev = false;
					continue;
				}
				else if (map[idx] == 'K')
				{
					kN = i, kM = j;
					mS = idx + nm;
				}
				else if (map[idx] == 'H')
				{
					hN = i, hM = j;
					mD = idx;
				}

				prev = idx - m;
				if (i > 0 && map[prev] != '#')
				{
					mEdges[idx + nm].push_back(prev);
					mEdges[prev].push_back(idx + nm);
					mEdges[prev + nm].push_back(idx);
					mEdges[idx].push_back(prev + nm);
					mCap[{idx + nm, prev}] = 1;
					mCap[{prev + nm, idx}] = 1;
				}

				if (j > 0 && bPrev)
				{
					prev = idx - 1;
					mEdges[idx + nm].push_back(prev);
					mEdges[prev].push_back(idx + nm);
					mEdges[prev + nm].push_back(idx);
					mEdges[idx].push_back(prev + nm);
					mCap[{idx + nm, prev}] = 1;
					mCap[{prev + nm, idx}] = 1;
				}

				bPrev = true;
			}
		}

		mbException = ex(kN, kM, hN, hM, n, m);
		if (mbException)
			return;

		for (int i = 0; i < nm; i++, idx++)
		{
			if (map[i] != '#')
			{
				mEdges[i].push_back(idx);
				mEdges[idx].push_back(i);
				mCap[{i, idx}] = mCap[{idx, i}] = 1;
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
				if (mLevel[next] < 0 && mCap[{now, next}] - mFlow[{now, next}] > 0)
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
				int f = mCap[{now, next}] - mFlow[{now, next}];
				if (f > 0)
				{
					int flow = dinic_dfs(next, min(nowFlow, f));
					if (flow > 0)
					{
						mFlow[{now, next}] += flow;
						mFlow[{next, now}] -= flow;
						return flow;
					}
				}
			}
		}

		return 0;
	}

	/*void group()
	{
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
	}*/

	bool ex(int kN, int kM, int hN, int hM, int n, int m)
	{
		if (kN == -1 || hN == -1)
			return true;

		int dN = abs(kN - hN);
		if (dN == 0)
		{
			if (abs(kM - hM) == 1)
				return true;
		}
		else if (dN == 1)
		{
			if (kM == hM)
				return true;
		}

		return false;
	}


private:
	vvi mEdges;
	map<pii, int> mCap, mFlow;
	vi mCheck, mLevel;
	int mN, mS, mD;
	bool mbException = false;;

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