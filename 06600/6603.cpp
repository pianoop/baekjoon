//로또
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef std::vector<int> vi;

class Lotto
{
public:
	Lotto(int n):mN(n)
	{
		input();
		solve();
	}	

	~Lotto()
	{
		delete[] mCheck;
	}


private:
	void input()
	{
		mNums.resize(mN);
		for (auto& n : mNums)
			std::cin >> n;

		mCnt = 1;
		for (int i = mN - 5; i <= mN; i++)
			mCnt *= i;
		mCnt /= 720;

		mCheck = new bool[mN];
		memset(mCheck, false, sizeof(bool) * mN);
	}

	void solve()
	{
		recur(0, 0);
	}

	void recur(int now, int i)
	{
		if (now == 6)
		{
			for (int i = 0; i < 6; i++)
				std::cout << mAns[i] << " ";
			std::cout << "\n";
			mCnt--;

			return;
		}

		int next = now + 1;
		for (; i < mN; i++)
		{
			if (!mCheck[i])
			{
				mCheck[i] = true;
				mAns[now] = mNums[i];
				recur(next, i + 1);

				if (mCnt == 0)
					return;

				mCheck[i] = false;
			}
		}
	}

private:
	vi mNums;
	int mAns[6];
	int mN, mCnt;
	bool* mCheck;
	
};

void Solve()
{
	int N;
	while (true)
	{
		std::cin >> N;
		if (N == 0)
			return;

		Lotto L(N);
		std::cout << "\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}