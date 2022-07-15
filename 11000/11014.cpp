//컨닝 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
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
			if (mPartner[i] < 0 && dfs(i))
				cnt++;
		}

		cout << mTot - cnt << "\n";
	}


private:
	void init()
	{
		int n, m;
		cin >> n >> m;
		mN = n * m;

		mEdges.resize(mN);
		mPartner.resize(mN, -1);
		mCheck.resize(mN);
		mMap.resize(mN);
		mTot = 0;

		char c;
		for (int i = 0; i < mN; i++)
		{
			cin >> c;
			if (c == 'x')
			{
				mMap[i] = -1;
				mTot++;
			}
		}

		mTot = mN - mTot;
		int LD = m - 1, RD = LD + 2;
		int k = 0, n1 = n - 1, m1 = m - 1;
		for (int i = 0; i < n1; i++)
		{
			// j = 0 일 때
			if (m1 > 0)
			{
				if (mMap[k] >= 0)
				{
					if (mMap[k + 1] >= 0)
					{
						mEdges[k + 1].push_back(k);
						mEdges[k].push_back(k + 1);
					}
					if (mMap[k + RD] >= 0)
					{
						mEdges[k + RD].push_back(k);
						mEdges[k].push_back(k + RD);
					}
				}
				k++;
			}
			// 그 사이
			for (int j = 1; j < m1; j++, k++)
			{
				if (mMap[k] >= 0)
				{
					if (mMap[k + 1] >= 0)
					{
						mEdges[k + 1].push_back(k);
						mEdges[k].push_back(k + 1);
					}
					if (mMap[k + LD] >= 0)
					{
						mEdges[k + LD].push_back(k);
						mEdges[k].push_back(k + LD);
					}
					if (mMap[k + RD] >= 0)
					{
						mEdges[k + RD].push_back(k);
						mEdges[k].push_back(k + RD);
					}
				}
			}

			// j = m1 일 때
			if (m1 > 0)
			{
				if (mMap[k] >= 0 && mMap[k + LD] >= 0)
				{
					mEdges[k + LD].push_back(k);
					mEdges[k].push_back(k + LD);
				}
				k++;
			}
		}
		//마지막 행
		for (int j = 0; j < m1; j++, k++)
		{
			if (mMap[k] >= 0 && mMap[k + 1] >= 0)
			{
				mEdges[k + 1].push_back(k);
				mEdges[k].push_back(k + 1);
			}
		}
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
				mPartner[now] = next;
				return true;
			}
		}

		return false;
	}


private:
	vvi mEdges;
	vi mPartner, mCheck, mMap;
	int mN, mTot;

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