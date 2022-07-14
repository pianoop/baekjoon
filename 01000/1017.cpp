//소수 쌍
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
		vi ans;
		int cnt, HalfN = mN >> 1;

		vi tmp0 = mEdges[0];
		mEdges[0].clear();

		for (auto i : tmp0)
		{
			vi tmpi = mEdges[i];
			mEdges[i].clear();
			mEdges[i].push_back(0);
			mEdges[0].push_back(i);
			fill(mPartner.begin(), mPartner.end(), -1);

			cnt = 0;
			for (int i = 0; i < mN; i++)
			{
				fill(mCheck.begin(), mCheck.end(), 0);
				if (mPartner[i] < 0 && dfs(i))
					cnt++;
			}

			if (cnt == HalfN)
				ans.push_back(mNums[i]);

			mEdges[i] = tmpi;
			mEdges[0].pop_back();
		}


		if (ans.empty())
			cout << -1;
		else
		{
			sort(ans.begin(), ans.end());

			for (auto i : ans)
				cout << i << " ";
		}
	}


private:
	void init()
	{
		cin >> mN;

		mCheck.resize(mN);
		mPartner.resize(mN, -1);
		mEdges.resize(mN);
		mNums.resize(mN);
		for (auto& p : mNums)
			cin >> p;

		bool Prime[2001];
		memset(Prime, -1, sizeof(Prime));
		for (int i = 2; i < 145; i++)
		{
			if (Prime[i])
			{
				for (int j = i << 1; j < 2001; j += i)
					Prime[j] = false;
			}
		}

		for (int i = 0; i < mN; i++)
		{
			int now = mNums[i];
			for (int j = i + 1; j < mN; j++)
			{
				if (Prime[now + mNums[j]])
				{
					mEdges[i].push_back(j);
					mEdges[j].push_back(i);
				}
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
	vi mNums, mPartner, mCheck;
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