//책 페이지
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
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
		int end = (int)mNums.size(), i = 0, ans = 0;

		for (int j = 0, tmp = mStart; j < end; j++, tmp /= 10)
		{
			if (0 < mNums[j])
				ans += mFronts[j] * tmp;
			else if (0 == mNums[j])
				ans += (mFronts[j] - 1) * tmp + mBacks[j] + 1;
		}
		cout << ans << " ";

		for (i = 1; i < 10; i++)
		{
			int tmp = mStart;
			ans = 0;

			for (int j = 0; j < end; j++, tmp/= 10)
			{
				if (i < mNums[j])
					ans += (mFronts[j] + 1) * tmp;
				else if (i == mNums[j])
					ans += mFronts[j] * tmp + mBacks[j] + 1;
				else
					ans += mFronts[j] * tmp;
			}

			cout << ans << " ";
		}
	}


private:
	void input()
	{
		cin >> mN;

		int div = 1'000'000'000;
		while (mN / div == 0)
			div /= 10;

		mStart = div;
		int back = mN, front = 0;
		mFronts.push_back(0);
		while (div > 0)
		{
			front *= 10;

			int tmp = back / div;
			back %= div;
			front += tmp;

			mNums.push_back(tmp);
			mFronts.push_back(front);
			mBacks.push_back(back);

			div /= 10;
		}
	}


private:
	vi mNums, mBacks, mFronts;
	int mN, mStart;


};


void Solve()
{
	Q ans;
	ans.Solve();
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}