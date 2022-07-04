//컨닝
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		cout << recur(0, 0, 0) << "\n";
	}


private:
	void input()
	{
		cin >> mNM >> mM;
		mNM *= mM;
		mMm = mM - 1;
		mLeft = 1 << mM;
		mNow = mLeft << 1;

		mDp.resize(mNM, vi(1 << (mM + 2), -1));
		mMap.resize(mNM);

		char c;
		for (auto& seat : mMap)
		{
			cin >> c;
			if (c != '.')
				seat = -1;
		}
	}

	int recur(int nm, int m, int bit)
	{
		if (nm >= mNM)
			return 0;
		

		int& now = mDp[nm][bit];
		if (now < 0)
			now = 0;
		else
			return now;
		
		if (mMap[nm] < 0 || bit & mNow)
			return now = max(now, recur(nm + 1, m + 1, bit >> 1));

		while (m >= mM)
			m -= mM;

		if (m > 0)
		{
			if (bit & 1 || bit & mLeft) // 좌상단, 좌
				return now = max(now, recur(nm + 1, m + 1, bit >> 1));
		}
		
		if (m < mMm)
		{
			if (bit & 4) // 우상단
				return now = max(now, recur(nm + 1, m + 1, bit >> 1));
		}

		//앉지 않음
		now = max(now, recur(nm + 1, m + 1, bit >> 1));
		
		//앉음
		now = max(now, 1 + recur(nm + 1, m + 1, (bit >> 1) | mLeft));

		return now;
	}

	

private:
	vvi mDp;
	vi mMap;
	int mNM, mM, mMm, mLeft, mNow;

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