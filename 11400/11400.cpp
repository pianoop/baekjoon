//단절선
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		for (int i = 1; i <= mV; i++)
		{
			if(mCheck[i] < 0)
				recur(i, 0);
		}

		sort(mBridges.begin(), mBridges.end());
		cout << mBridges.size() << "\n";
		for(auto& i : mBridges)
			cout << i.first << " " << i.second << "\n";

	}


private:
	void input()
	{
		int E, a, b;
		cin >> mV >> E;

		mEdges.resize(mV + 1);
		mCheck.resize(mV + 1, -1);
		while (E--)
		{
			cin >> a >> b;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
		}
	}


	int recur(int now, int parent)
	{
		int Min;
		Min = mCheck[now] = ++mCnt;

		for (auto next : mEdges[now])
		{
			if (next == parent)
				continue;

			if (mCheck[next] < 0 )
			{
				int tmp = recur(next, now);

				if (tmp > mCheck[now])
					mBridges.push_back({ min(now, next), max(now, next) });

				Min = min(Min, tmp);
			}
			else
				Min = min(Min, mCheck[next]);
		}
		

		return Min;
	}

private:
	vvi mEdges;
	vector<pii> mBridges;
	vi mCheck;
	int mV, mCnt = 0;

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