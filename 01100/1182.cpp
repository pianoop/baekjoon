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
		
	}


private:
	void input()
	{
		std::cin >> mN >> mS;
		mNums.resize(mN);

		for (auto& n : mNums)
			std::cin >> n;
	}

	void solve()
	{
		recur(0, 0);
		if (mS == 0)
			mAns--;

		std::cout << mAns;
	}

	void recur(int i, int total)
	{
		if (i == mN)
		{
			if (total == mS)
				mAns++;
			return;
		}
		
		recur(i + 1, total + mNums[i]);
		recur(i + 1, total);
	}

private:
	vi mNums;
	int mN, mS, mAns = 0;
	
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