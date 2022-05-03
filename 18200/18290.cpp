//NM과 K (1)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

const int MAX = 16384;

class Temp
{
public:
	Temp()
	{
		input();
		solve();
	}

private:
	void input()
	{
		std::cin >> mN >> mM >> mK;
		mArr.resize(mN, vi(mM));

		for (auto& a : mArr)
			for (auto& b : a)
				std::cin >> b;
	}

	void solve()
	{
		int temp;
		for (int i = 0; i < mN - 1; i++)
			for (int j = 0; j < mM; j++)
			{
				int ii = i + 1;
				temp = mArr[ii][j];
				mArr[ii][j] = X;
				recur(i, j, 1, mArr[i][j]);

				mArr[ii][j] = temp;
			}

		int i = mN - 1;
		for(int j=0;j<mM;j++)
			recur(i, j, 1, mArr[i][j]);

		std::cout << mAns;
	}

	void recur(int i0, int j0, int n, int total)
	{
		if (n == mK)
		{
			mAns = std::max(mAns, total);
			return;
		}

		int i,j, temp;
		for (j = j0 + 2; j < mM; j++)
		{
			if (mArr[i0][j] < MAX)
			{
				int ii = i0 + 1;
				if (ii < mN)
				{
					temp = mArr[ii][j];
					mArr[ii][j] = X;
					recur(i0, j, n + 1, total + mArr[i0][j]);
					mArr[ii][j] = temp;
				}
				else
					recur(i0, j, n + 1, total + mArr[i0][j]);
			}
		}

		for (i = i0 + 1; i < mN; i++)
		{
			for (int j = 0; j < mM; j++)
			{
				if (mArr[i][j] < MAX)
				{
					int ii = i + 1;
					if (ii < mN)
					{
						temp = mArr[ii][j];
						mArr[ii][j] = X;
						recur(i, j, n + 1, total + mArr[i][j]);
						mArr[ii][j] = temp;
					}
					else
						recur(i, j, n + 1, total + mArr[i][j]);
				}
			}
		}

	}

private:
	int mN, mM, mK, mAns = -1000000;
	const int X = 1<<20;
	vvi mArr;
};

void Solve()
{
	Temp NM;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}