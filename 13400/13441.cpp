//마법의 나무
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

		cout << mN - cnt;
	}


private:
	void init()
	{
		cin >> mN;
		mEdges.resize(mN);
		mPartner.resize(mN, -1);
		mCheck.resize(mN);

		vector<vector<char> > edges(mN, vector<char>(mN));
		for (auto& vc : edges)
			for (auto& c : vc)
				cin >> c;

		for (int k = 0; k < mN; k++)
		{
			for (int i = 0; i < mN; i++)
			{
				for (int j = 0; j < mN; j++)
				{
					if (edges[i][k] & 1 && edges[k][j] & 1)
						edges[i][j] = '1';
				}
			}
		}

		for (int i = 0; i < mN; i++)
		{
			for (int j = 0; j < mN; j++)
			{
				if (edges[i][j] & 1)
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

	bool cycle(int now, const int head)
	{
		while (now >= 0)
		{
			if (now == mPartner[now])
				return true;
			now = mPartner[now];
			if (now == head)
				return true;
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