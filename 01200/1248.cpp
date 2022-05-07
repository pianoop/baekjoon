//Guess
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;

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
		std::cin >> mN;
		mDP.resize(mN + 1, vi(mN));
		mAns.resize(mN);
		mSigns.resize(mN,vc(mN));
		int n = mN;
		for (int i = 0; i < mN; i++)
		{
			for (int j = i; j < mN; j++)
				std::cin >> mSigns[i][j];
		}
	}

	void solve()
	{
		recur(mN - 1);
	}

	void recur(int now)
	{
		if (now == -1)
		{
			for (auto ans : mAns)
				std::cout << ans << " ";

			mbEnd = true;
			return;
		}

		int down = now + 1, next = now - 1;
		if (mSigns[now][now] == '+')
		{
			for (int i = 1; i <= 10; i++)
			{
				bool flag = false;
				mDP[now][now] = i;
				for (int col = now + 1; col < mN; col++)
				{
					int& DP = mDP[now][col];
					DP = mDP[down][col] + i;

					if (mSigns[now][col] == '+')
					{
						if (!(DP > 0))
						{
							flag = true;
							break;
						}
					}
					else if (mSigns[now][col] == '-')
					{
						if (!(DP < 0))
						{
							flag = true;
							break;
						}
					}
					else if (DP != 0)
					{
						flag = true;
						break;
					}
				}
				if (flag)
					continue;

				mAns[now] = i;
				recur(next);
				if (mbEnd)
					return;
			}
		}
		else if (mSigns[now][now] == '-')
		{
			for (int i = -10; i < 0; i++)
			{
				bool flag = false;
				mDP[now][now] = i;
				for (int col = now + 1; col < mN; col++)
				{
					int& DP = mDP[now][col];
					DP = mDP[down][col] + i;

					if (mSigns[now][col] == '+')
					{
						if (!(DP > 0))
						{
							flag = true;
							break;
						}
					}
					else if (mSigns[now][col] == '-')
					{
						if (!(DP < 0))
						{
							flag = true;
							break;
						}
					}
					else if (DP != 0)
					{
						flag = true;
						break;
					}
				}
				if (flag)
					continue;

				mAns[now] = i;
				recur(next);
				if (mbEnd)
					return;
			}
		}
		else
		{
			mDP[now][now] = 0;
			for (int col = now + 1; col < mN; col++)
			{
				int& DP = mDP[now][col];
				DP = mDP[now + 1][col] ;

				if (mSigns[now][col] == '+')
					if (!(DP > 0))
						break;
				else if (mSigns[now][col] == '-')
					if (!(DP < 0))
						break;
				else if (DP != 0)
					break;
			}

			mAns[now] = 0;
			recur(next);
		}
	}

private:
	vvi mDP;
	vvc mSigns;
	vi mAns;
	int mN;
	bool mbEnd= false;

};

void Solve()
{
	Temp Q;

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}