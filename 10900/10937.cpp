//두부 모판 자르기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		recur(0, 0, 0);

		std::cout << mDp[0][0];
	}


private:
	void input()
	{
		std::cin >> mM;
		mNM = mM * mM;
		mBit = 1 << mM;
		mMm1 = mM - 1;
		mNMmM = mNM - mM;

		mMap.resize(mNM);
		char c;
		for (auto& i : mMap)
		{
			std::cin >> c;
			if (c == 'F')
				i =3;
			else
				i = c - 65;
		}

		mDp.resize(mNM, vi(mBit, -1));
	}

	int recur(int nm, int m, int bit)
	{
		if (nm >= mNM)
			return 0;
		else if (bit & 1)
			return recur(nm + 1, m + 1, bit >> 1);

		int& nowDp = mDp[nm][bit];
		auto& nowSc = mScore[mMap[nm]];

		if (nowDp != -1)
			return nowDp;

		if (m >= mM)
			m %= mM;

		bool bNext = bit & 2;
		int next = 2, nextBit = 4;
		while (bit & nextBit)
		{
			next++;
			nextBit <<= 1;
		}

		if (bNext)
		{
			nowDp = recur(nm + next, m + next, bit >> next); // 그냥 건너뜀

			if (nm < mNMmM) // 1 X 2
				nowDp = std::max(nowDp, nowSc[mMap[nm + mM]] + recur(nm + next, m + next, ((bit >> 1) | (1 << mMm1)) >> (next - 1)));
		}
		else
		{
			nowDp = recur(nm + 1, m + 1, bit >> 1);  // 그냥 건너뜀

			if (nm < mNMmM) // 1 X 2
				nowDp = std::max(nowDp, nowSc[mMap[nm + mM]] + recur(nm + 1, m + 1, (bit >> 1) | (1 << mMm1)));
			if (m < mMm1)   // 2 X 1
				nowDp = std::max(nowDp, nowSc[mMap[nm + 1]] + recur(nm + next, m + next, bit >> next));
		}

		return nowDp;
	}


private:
	vvi mDp;
	vi mMap;
	int mScore[4][4] = { {100, 70, 40, 0} ,{70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0} };
	int mNM, mM, mMm1, mNMmM, mBit;  //mMm1 = mM - 1, mNMmM = mNM - mM

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