//Parcel
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		if (middle())
			cout << "YES";
		else
			cout << "NO";
	}


private:
	void input()
	{
		cin >> mW >> mN;

		int tmp;
		mNums.resize(mN);
		for (auto& i : mNums)
			cin >> i;

		sort(mNums.begin(), mNums.end());
	}

	bool middle()
	{
		bool mNums1[400001] = {0,};

		int end = mN - 2;
		for (int L2 = 1; L2 < end; L2++)
		{
			int nowL2 = mNums[L2];
			for (int L1 = 0; L1 < L2; L1++)
				mNums1[nowL2 + mNums[L1]] = true;


			int nowR1W = mW - mNums[L2 + 1];
			for (int R2 = L2 + 2; R2 < mN; R2++)
			{
				int tmp = nowR1W - mNums[R2];
				if (!(tmp < 0) && tmp <= 400000 && mNums1[tmp])
					return true;
			}

		}

		return false;
	}


private:
	vi mNums;
	int mW, mN;

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