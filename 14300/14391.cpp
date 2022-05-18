//종이 조각
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
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
		recur(0, 0, 0);

		std::cout << mAns;
	}

private:
	void input()
	{
		memset(mCheck, false, sizeof(mCheck));
		std::cin >> mN >> mM;
		mFin = mN * mM;
		mPaper.resize(mN, vi(mM));

		char tmp;
		for (auto& P : mPaper)
		{
			for (auto& p : P)
			{
				std::cin >> tmp;
				p = tmp - 48;
			}
		}
	}

	void recur(int row, int cnt, int tot)
	{
		if (cnt == mFin)
		{
			mAns = std::max(mAns, tot);
			return;
		}

		cnt++;
		int tmp;
		for (int i = row; i < mN; i++)
		{
			for (int j = 0; j < mM; j++)
			{
				if (!mCheck[i][j])
				{
					mCheck[i][j] = true;
					tmp = mPaper[i][j];
					recur(i, cnt, tmp + tot);

					int ij = i, ccnt = cnt;
					while (++ij < mN && mCheck[ij][j] == false)
					{
						tmp *= 10;
						tmp += mPaper[ij][j];
						mCheck[ij][j] = true;
						recur(i, ++ccnt, tot + tmp);
					}

					while (--ij > i)
						mCheck[ij][j] = false;

					tmp = mPaper[i][j];
					ij = j, ccnt = cnt;
					while (++ij < mM && mCheck[i][ij] == false)
					{
						tmp *= 10;
						tmp += mPaper[i][ij];
						mCheck[i][ij] = true;
						recur(i, ++ccnt, tot + tmp);
					}

					while (--ij > j)
						mCheck[i][ij] = false;


					mCheck[i][j] = false;
					return;
				}
			}
		}


	}

private:
	bool mCheck[4][4];
	int mN, mM, mFin, mAns = 0;
	vvi mPaper;


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