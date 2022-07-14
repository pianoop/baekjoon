//열혈강호 3
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
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
			fill(mCheck.begin(), mCheck.end(), 0);
			if (dfs(i))
				cnt++;
		}

		int countK = 0;
		for (int i = 1; i < mN && countK < mK; i++)
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			if (dfs(i))
				countK++;
		}

		cout << cnt + countK;
	}


private:
	void init()
	{
		cin >> mN >> mM >> mK;
		mN++, mM++;

		mCheck.resize(mN);
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
	int mN, mM, mK;

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