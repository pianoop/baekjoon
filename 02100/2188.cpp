//축사 배정
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <bitset>
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

		for (int i = 1; i < mN; i++)
		{
			mCheck.reset();

			if (dfs(i))
				cnt++;
		}

		cout << cnt;
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mN++, mM++;
		
		mPartner.resize(mM, -1);
		mEdges.resize(mN);
		for (int i = 1; i < mN; i++)
		{
			int T, tmp;
			cin >> T;

			auto& now = mEdges[i];
			while (T--)
			{
				cin >> tmp;
				now.push_back(tmp);
			}

			sort(now.begin(), now.end());
		}
	}

	bool dfs(int now)
	{
		if (mCheck.test(now))
			return false;
		mCheck.set(now, true);

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
	bitset<201> mCheck;
	vvi mEdges;
	vi mPartner;
	int mN, mM;

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