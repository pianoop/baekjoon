//비숍
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<bool> vb;
typedef std::vector<std::pair<int, int> > vpi;

class Chessboard
{
public:
	Chessboard(int n) :mN(n)
	{
		mPosDiags.resize(mN * 2, 1);
		mNegDiags.resize(mN * 2, 1);
		mTrackingEvenArr.reserve(mN * mN / 2);
		mTrackingOddArr.reserve(mN * mN / 2);
	}

	void Inputarr()
	{
		for (int i = 0; i < mN; i++)
		{
			int temp;
			for (int j = 0; j < mN; j++)
			{
				std::cin >> temp;
				if (temp == 1)
				{
					if((i+j)%2==0)
						mTrackingEvenArr.push_back({ i - j + mN,i + j });
					else
						mTrackingOddArr.push_back({ i - j + mN,i + j });
				}
			}
		}
	}

	void Backtracking()
	{
		BacktrackingEven(0, 0);
		BacktrackingOdd(0, 0);
	}

	void BacktrackingEven(int now, int bishopCnt)
	{
		if (now == int(mTrackingEvenArr.size()))
		{
			if (bishopCnt > mMaxEvenBishop)
				mMaxEvenBishop = bishopCnt;
			return;
		}

		if (mPosDiags[mTrackingEvenArr[now].first] && mNegDiags[mTrackingEvenArr[now].second])
		{
			mPosDiags[mTrackingEvenArr[now].first] = mNegDiags[mTrackingEvenArr[now].second] = 0;
			BacktrackingEven(now + 1, bishopCnt + 1);

			mPosDiags[mTrackingEvenArr[now].first] = mNegDiags[mTrackingEvenArr[now].second] = 1;
		}
		BacktrackingEven(now + 1, bishopCnt);
	}

	void BacktrackingOdd(int now, int bishopCnt)
	{
		if (now == int(mTrackingOddArr.size()))
		{
			if (bishopCnt > mMaxOddBishop)
				mMaxOddBishop = bishopCnt;
			return;
		}

		if (mPosDiags[mTrackingOddArr[now].first] && mNegDiags[mTrackingOddArr[now].second])
		{
			mPosDiags[mTrackingOddArr[now].first] = mNegDiags[mTrackingOddArr[now].second] = 0;
			BacktrackingOdd(now + 1, bishopCnt + 1);

			mPosDiags[mTrackingOddArr[now].first] = mNegDiags[mTrackingOddArr[now].second] = 1;
		}
		BacktrackingOdd(now + 1, bishopCnt);
	}

	void Printans()
	{
		printf("%d", mMaxEvenBishop + mMaxOddBishop);
	}

private:
	int mN, mMaxEvenBishop = 0, mMaxOddBishop = 0;
	vb mPosDiags, mNegDiags;
	vpi mTrackingEvenArr, mTrackingOddArr;
};

void Solve()
{
	int N;
	std::cin >> N;

	Chessboard chess(N);
	chess.Inputarr();
	chess.Backtracking();
	chess.Printans();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}