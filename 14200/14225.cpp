//부분수열의 합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef std::vector<int> vi;

class SubSeq
{
public:
	SubSeq()
	{
		input();
		solve();
	}	

	~SubSeq()
	{
		delete[] mbCheck;
	}


private:
	void input()
	{
		std::cin >> mN;
		mNums.resize(mN);

		mMax = 2;
		for (auto& n : mNums)
		{
			std::cin >> n;
			mMax += n;
		}
		
		mbCheck = new bool[mMax];
		memset(mbCheck, false, sizeof(bool) * mMax);
	}

	void solve()
	{
		recur(0, 0);

		for (int i = 1; i < mMax; i++)
		{
			if (!mbCheck[i])
			{
				std::cout << i;
				break;
			}
		}
	}

	void recur(int i, int total)
	{
		if (i == mN)
		{
			mbCheck[total] = true;
			return;
		}
		
		recur(i + 1, total + mNums[i]);
		recur(i + 1, total);
	}

private:
	vi mNums;
	int mN, mMax;
	bool* mbCheck;
};

void Solve()
{
	SubSeq Q;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}