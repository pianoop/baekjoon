//룩 어택
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
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
		int cnt = 0;
		for (int i = 1; i < mR; i++)
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
		int n;
		cin >> mR >> mC >> n;
		mR++, mC++;
		mEdges.resize(mR);
		mCheck.resize(mR);
		mPartner.resize(mC, -1);

		vvi blank(mR, vi(mC));
		int r, c;
		while (n--)
		{
			cin >> r >> c;
			blank[r][c] = -1;
		}

		for (int i = 1; i < mR; i++)
		{
			auto& now = blank[i];

			for (int j = 1; j < mC; j++)
			{
				if (now[j] >= 0)
					mEdges[i].push_back(j);
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
				return true;
			}
		}

		return false;
	}


private:
	vvi mEdges;
	vi mPartner, mCheck;
	int mR, mC;

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