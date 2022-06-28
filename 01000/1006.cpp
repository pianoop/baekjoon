//습격자 초라기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
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
		//Case1 기본 시작
		int ans = recur(0, 0, true);

		if (mN > 2)
		{
			bool right = mW >= mEnemy[1] + mEnemy[mN - 1] ? true : false
				, left = mW >= mEnemy[0] + mEnemy[mN - 2] ? true : false;

			//Case2 막 줄 0 1
			if (right)
			{
				dpReset();

				mN--;
				if (mW >= mEnemy[0] + mEnemy[2])
					ans = min(ans, 2 + recur(3, 0, false));
				else
					ans = min(ans, 2 + recur(2, 0, true));

				mN++;
			}

			//Case3 막 줄 1 1
			if (left && right)
			{
				dpReset();

				mN -= 2;
				ans = min(ans, 2 + recur(2, 0, true));

				mN += 2;
			}

			//Case4 막 줄 1 0
			if (left)
			{
				dpReset();

				if (mW >= mEnemy[mN - 1] + mEnemy[mN - 3])
				{
					mN -= 3;
					ans = min(ans, 2 + recur(1, 0, false));

					mN += 3;
				}
				else
				{
					mN -= 2;
					ans = min(ans, 2 + recur(1, 0, false));

					mN += 2;
				}
			}
		}

		cout << ans << "\n";
	}


private:
	void input()
	{
		cin >> mN >> mW;
		mN <<= 1;
		mDp.resize(mN, vi(4, -1));
		mEnemy.resize(mN + 2);
		for (int i = 0; i < mN; i += 2)
			cin >> mEnemy[i];
		for (int i = 1; i < mN; i += 2)
			cin >> mEnemy[i];
	}

	int recur(int nm, int bit, bool bEven)
	{
		if (nm >= mN)
			return 0;
		else if (bit & 1)
		{
			if (bit & 2)
				return recur(nm + 2, 0, bEven);
			return recur(nm + 1, bit >> 1, !bEven);
		}

		int& now = mDp[nm][bit];
		if (now != -1)
			return now;
		


		int R = mW - mEnemy[nm];

		//현재 위치만
		now = recur(nm + 1, bit >> 1, !bEven);


		//우측
		if (bEven && !(bit & 2) && (mEnemy[nm + 1] <= R))
			now = min(now, recur(nm + 2, 0, bEven));


		//하단
		if (mEnemy[nm + 2] <= R)
			now = min(now, recur(nm + 1, (bit >> 1) | 2, !bEven));

		now++;
		return now;
	}

	void dpReset()
	{
		for (auto& i : mDp)
			for (auto& j : i)
				j = -1;
	}


private:
	vvi mDp;
	vi mEnemy;
	int mN, mW;

};


void Solve()
{
	int T;
	cin >> T;

	while (T--)
	{
		Q ans;
		ans.Solve();
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}