//점프
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		mDp[0][0] = 0;
		mDp[mN][mN] = 1;
		recur(0, 0);

		std::cout << mDp[0][0];

	}


private:
	void input()
	{
		std::cin >> mN;
		mMap.resize(mN, vi(mN));
		mDp.resize(mN, vl(mN, -1));
		mN--;		//mN 1개 줄임에 주의

		for (auto& i : mMap)
			for (auto& j : i)
				std::cin >> j;
	}

	void recur(int r, int c)
	{
		if (mMap[r][c] == 0)
			return;

		int next = c + mMap[r][c];
		if (next <= mN && mDp[r][next] != 0)
		{
			if (mDp[r][next] == -1)
			{
				mDp[r][next] = 0;
				recur(r, next);
			}

			mDp[r][c] += mDp[r][next];
		}

		next = r + mMap[r][c];
		if (next <= mN && mDp[next][c] != 0)
		{
			if (mDp[next][c] == -1)
			{
				mDp[next][c] = 0;
				recur(next, c);
			}

			mDp[r][c] += mDp[next][c];
		}

	}


private:
	int mN;
	vvi mMap;
	vvl mDp;

};

void Solve()
{
	Q q;
	q.Solve();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}