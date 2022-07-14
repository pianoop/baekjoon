//열혈강호 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <bitset>
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
		mN = mN << 1;
		mN++, mM++;

		mPartner.resize(mM, -1);
		mEdges.resize(mN);
		for (int i = 1; i < mN; i += 2)
		{
			int T, tmp;
			cin >> T;

			auto& now1 = mEdges[i];
			auto& now2 = mEdges[i + 1];
			while (T--)
			{
				cin >> tmp;
				now1.push_back(tmp);
				now2.push_back(tmp);
			}
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
	bitset<2001> mCheck;
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