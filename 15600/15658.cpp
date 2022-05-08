//연산자 끼워넣기 (2)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Oper
{
public:
	Oper()
	{
		input();
		solve();
	}

	~Oper()
	{

	}


private:
	void input()
	{
		std::cin >> mN;
		mNums.resize(mN);

		for (auto& n : mNums)
			std::cin >> n;

		for (int i = 0; i < 4; i++)
			std::cin >> mOpers[i];
	}

	void solve()
	{
		recur(1, mNums[0]);

		std::cout << mMax << "\n" << mMin;
	}

	void recur(int now, int total)
	{
		if (now == mN)
		{
			mMax = std::max(mMax, total);
			mMin = std::min(mMin, total);

			return;
		}

		int next = now + 1;
		if (mOpers[0] > 0)
		{
			mOpers[0]--;
			recur(next, total + mNums[now]);

			mOpers[0]++;
		}

		if (mOpers[1] > 0)
		{
			mOpers[1]--;
			recur(next, total - mNums[now]);

			mOpers[1]++;
		}

		if (mOpers[2] > 0)
		{
			mOpers[2]--;
			recur(next, total * mNums[now]);

			mOpers[2]++;
		}

		if (mOpers[3] > 0)
		{
			mOpers[3]--;
			recur(next, total / mNums[now]);

			mOpers[3]++;
		}

	}

private:
	vi mNums;
	int mOpers[4];
	int mN, mMax = -1'000'000'000, mMin = 1'000'000'000;

};

void Solve()
{
	Oper Q;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}