//열혈강호 4
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
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
		int ans = 0, cnt = 0;
		for (int i = 1; i < mN; i++)
		{
			if (dfs(i))
				ans++;
			mCnt++;
		}

		bool endFlag = false;
		for (int i = 1; i < mN; i++)
		{
			while (dfs(i))
			{
				cnt++;
				if (cnt == mK)
				{
					endFlag = true;
					break;
				}

				mCnt++;
			}
			mCnt++;

			if (endFlag)
				break;
		}
		cout << ans + cnt;
	}


private:
	void init()
	{
		cin >> mN >> mM >> mK;
		mN++, mM++;
		mEdges.resize(mN);
		mCheck.resize(mN);
		mPartner.resize(mM, -1);

		int n, b;
		for (int i = 1; i < mN; i++)
		{
			cin >> n;
			while (n--)
			{
				cin >> b;
				mEdges[i].push_back(b);
			}
		}
	}

	bool dfs(int now)
	{
		if (mCheck[now] == mCnt)
			return false;
		mCheck[now] = mCnt;

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
	vi mCheck, mPartner;
	int mN, mM, mK, mCnt = 1;

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