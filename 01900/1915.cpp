//가장 큰 정사각형
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;
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
		int Max = 0;

		for (int i = 1; i < mN; i++)
		{
			for (int j = 1; j < mM; j++)
			{
				if (mMap[i][j] == '1')
				{
					mDp[i][j] = std::min(mDp[i][j - 1], std::min(mDp[i - 1][j - 1], mDp[i - 1][j])) + 1;
					Max = std::max(Max, mDp[i][j]);
				}
			}
		}
		
		std::cout << Max * Max;
	}


private:
	void input()
	{
		std::cin >> mN >> mM;
		mN += 2, mM += 2;

		mDp.resize(mN, vi(mM));
		mMap.resize(mN, vc(mM));
		mN--, mM--;

		for (int i = 1; i < mN; i++)
			for (int j = 1; j < mM; j++)
				std::cin >> mMap[i][j];
	}


private:
	vvi mDp;
	vvc mMap;
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