//상어의 저녁식사
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Tri
{
public:
	int a, b, c;
};

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

			fill(mCheck.begin(), mCheck.end(), 0);
			if (dfs(i))
				cnt++;
		}

		cout << mN - cnt;
	}


private:
	void init()
	{
		cin >> mN;

		mCheck.resize(mN);
		mPartner.resize(mN, -1);
		mEdges.resize(mN);

		vector<Tri> status(mN);
		for (auto& [a, b, c] : status)
			cin >> a >> b >> c;

		for(int i = 0; i < mN; i++)
		{
			auto [a, b, c] = status[i];
			for (int j = i + 1; j < mN; j++)
			{
				auto [a2, b2, c2] = status[j];
				if (a >= a2 && b >= b2 && c >= c2)
					mEdges[i].push_back(j);
				else if (a <= a2 && b <= b2 && c <= c2)
					mEdges[j].push_back(i);	
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