//최소 체인 커버
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
		for (int i = 1; i < mN; i++)
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			dfs(i);
		}

		int cnt = 0;
		vi check(mN);
		for (int i = 1; i < mN; i++)
		{
			if (check[i] >= 0)
			{
				int now = i;
				bool flag = true;
				while (true)
				{
					check[now] = -1;
					now = mPartner[now];
					if (now < 0)
						break;
					else if (check[now] < 0)
					{
						flag = false;
						break;
					}
				}

				if (flag)
					cnt++;
			}
		}

		cout << cnt;
	}


private:
	void init()
	{
		int m;
		cin >> mN >> m;
		mN++;
		mEdges.resize(mN);
		mPartner.resize(mN, -1);
		mCheck.resize(mN);

		int a, b;
		while (m--)
		{
			cin >> a >> b;
			mEdges[a].push_back(b);
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