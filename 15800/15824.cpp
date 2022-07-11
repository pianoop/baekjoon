//너 봄에는 캡사이신이 맛있단다
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int DIV = 1'000'000'007;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		ll ans = 0;
		int mNm1 = mN - 1;
		for (int i = 1; i < mNm1; i++)
			ans += (ll)mNums[i] * (mPows[i] - mPows[mN - i - 1]) % DIV;

		ans += ll(mNums.back() - mNums.front()) * (mPows[mN - 1] - 1);
		ans %= DIV;

		cout << ans;
	}


private:
	void input()
	{
		cin >> mN;
		mNums.resize(mN);

		for (auto& num : mNums)
			cin >> num;

		sort(mNums.begin(), mNums.end());

		mPows.resize(mN);
		mPows[0] = 1;
		for (int i = 1; i < mN; i++)
			mPows[i] = (mPows[i - 1] << 1) % DIV;
	}

private:
	vi mNums, mPows;
	int mN;
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