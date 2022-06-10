//로봇 조종하기
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
		int flow;

		for (int i = 1; i < mN; i++)
		{
			for (auto& j : mMap)
				std::cin >> j;

			flow = 0;
			mDp1[0] = mMap[0] + mPrev[0];
			while (++flow < mM)
				mDp1[flow] = std::max(mDp1[flow - 1], mPrev[flow]) + mMap[flow];

			flow--;
			mDp2[flow] = mMap[flow] + mPrev[flow];
			while (--flow >= 0)
				mDp2[flow] = std::max(mDp2[flow + 1], mPrev[flow]) + mMap[flow];

			while (++flow < mM)
			{
				mPrev[flow] = std::max(mDp1[flow], mDp2[flow]);
			}
		}

		std::cout << mPrev[mM - 1];
	}


private:
	void input()
	{
		std::cin >> mN >> mM;
		mDp1.resize(mM);
		mDp2.resize(mM);
		mMap.resize(mM);
		mPrev.resize(mM);

		int tot = 0, tmp;
		for (int i = 0; i < mM; i++)
		{
			std::cin >> tmp;
			tot += tmp;
			mPrev[i] = tot;
		}
	}


private:
	vi mDp1, mDp2, mMap, mPrev;
	int mN, mM;

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