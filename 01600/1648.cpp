//격자판 채우기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


const int DIV = 9901;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		if (mNM & 1)
			std::cout << 0;
		else
		{
			mDp.resize(mNM, vi(mBit, -1));
			recur(0, 0, 0);

			std::cout << mDp[0][0];
		}
	}


private:
	void input()
	{
		std::cin >> mNM >> mM;
		mNM *= mM;
		mBit = 1 << mM;
		mMm1 = mM-1;
	}

	int recur(int nm, int m, int bit)
	{
		if (nm >= mNM)
		{
			if (nm == mNM && bit == 0)
				return 1;
			else
				return 0;
		}
		else if (bit & 1)
		{
			std::cout << nm << " || " << m << " || " << bit << "\n";
			return recur(nm + 1, m + 1, bit >> 1);
		}

		int& now = mDp[nm][bit];
		if (now != -1)
			return now;
		else
			now = 0;

		if (m >= mM)
			m %= mM;

		bool bNext = bit & 2;
		int next = 2, nextBit = 4;
		while (bit & nextBit)
		{
			next++;
			nextBit <<= 1;
		}

		//1 X 2
		if (bNext)
			now += recur(nm + next, m + next, ((bit >> 1) | (1 << mMm1)) >> (next - 1));
		else
			now += recur(nm + 1, m + 1, (bit >> 1) | (1 << mMm1));

		//2 X 1
		if (m < mMm1 && !bNext)
			now += recur(nm + next, m + next, bit >> next);

		now %= DIV;
		return now;
	}


private:
	vvi mDp;
	int mNM, mM, mMm1, mBit;  //mMm1 = mM - 1

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