//비숍2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
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
		int cnt = 0;
		for (int i = 0; i < mN; i++)
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			if (dfs(i))
				cnt++;
		}

		cout << cnt;
	}


private:
	void init()
	{
		int n, m;
		cin >> n >> m;
		mN = n << 1;
		mEdges.resize(n * n);

		int a, b;
		vvi map(n + 1, vi(n + 1));
		while (m--)
		{
			cin >> a >> b;
			map[a][b] = -1;
		}

		int cntRD = 0, cnt = -1, prevX = 0;
		vector<pii> idxRD(mN + 1);
		for (int i = n; i > 0; i--)
		{
			prevX = 0;

			for (int i1 = i, j1 = 1; i1 <= n; i1++, j1++)
			{
				pii& now = idxRD[i1 + j1];

				if (map[i1][j1] < 0)
				{
					now.second = 0;
					prevX = 0;
				}
				else
				{
					if (now.second < 0)
					{
						if (prevX < 0)
							mEdges[now.first].push_back(cnt);
						else
						{
							mEdges[now.first].push_back(++cnt);
							prevX = -1;
						}
					}
					else
					{
						now.first = cntRD++;

						if (prevX < 0)
							mEdges[now.first].push_back(cnt);
						else
						{
							mEdges[now.first].push_back(++cnt);
							prevX = -1;
						}

						now.second = -1;
					}
				}
			}
		}

		for (int j = 2; j <= n; j++)
		{
			prevX = 0;

			for (int i1 = 1, j1 = j; j1 <= n; i1++, j1++)
			{
				pii& now = idxRD[i1 + j1];

				if (map[i1][j1] < 0)
				{
					now.second = 0;
					prevX = 0;
				}
				else
				{
					if (now.second < 0)
					{
						if (prevX < 0)
							mEdges[now.first].push_back(cnt);
						else
						{
							mEdges[now.first].push_back(++cnt);
							prevX = -1;
						}
					}
					else
					{
						now.first = cntRD++;

						if (prevX < 0)
							mEdges[now.first].push_back(cnt);
						else
						{
							mEdges[now.first].push_back(++cnt);
							prevX = -1;
						}

						now.second = -1;
					}
				}
			}
		}

		mN = cntRD;
		mPartner.resize(cnt + 1, -1);
		mCheck.resize(mN);
	}

	bool dfs(int now)
	{
		if (mCheck[now] < 0)
			return false;
		mCheck[now] = -1;

		for (auto next : mEdges[now])
		{
			if (mPartner[next] < 0 || dfs(mPartner[next]))
			{
				mPartner[next] = now;
				return true;
			}
		}

		return false;
	}


private:
	vvi mEdges;
	vi mPartner, mCheck;
	int mN;

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