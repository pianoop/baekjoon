//단방향 링크 네트워크
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

		cout << cnt << "\n";
	}


private:
	void init()
	{
		int m;
		cin >> mN >> m;
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