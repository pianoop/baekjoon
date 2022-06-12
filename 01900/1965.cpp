//상자넣기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int Max = 0;

		for (int i = 0; i < mN; i++)
		{
			int now = mBox[i], nowDp = mDp[i] + 1;

			for (int j = i + 1; j < mN; j++)
			{
				if (mBox[j] > now && nowDp > mDp[j])
					mDp[j] = nowDp;
			}

			Max = std::max(Max, mDp[i]);
		}

		std::cout << Max + 1;
	}


private:
	void input()
	{
		std::cin >> mN;
		mDp.resize(mN);
		mBox.resize(mN);
		for (auto& i : mBox)
			std::cin >> i;
	}


private:
	vi mDp, mBox;
	int mN;

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