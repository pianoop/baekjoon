//열쇠
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;
typedef std::pair<int, int> pi;
#define nown BFSbox.front().first
#define nowm BFSbox.front().second

class Thief
{
public:
	Thief()
	{
		//Input
		std::cin >> mN >> mM;
		mMap.resize(mN + 2, vc(mM + 2, '*'));
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				std::cin >> mMap[i][j];
				if (mMap[i][j] > 46 && mMap[i][j] < 97)
					mMap[i][j] -= 65;
			}
		}
		std::string str;
		std::cin >> str;
		if (str[0] != '0')
		{
			for (auto c : str)
			{
				mKeybit |= (1 << (c - 97));
			}
		}
		//
		for (int j = 1; j <= mM; j++)
		{
			if (mMap[1][j] > 90)
			{
				mKeybit |= (1 << (mMap[1][j] - 97));
				mMap[1][j] = '.';
			}
			else if (mMap[1][j] == '$')
			{
				mMoney++;
				mMap[1][j] = '.';
			}
			if (mMap[mN][j] > 90)
			{
				mKeybit |= (1 << (mMap[mN][j] - 97));
				mMap[mN][j] = '.';
			}
			else if (mMap[mN][j] == '$')
			{
				mMoney++;
				mMap[mN][j] = '.';
			}
		}

		for (int i = 1; i < mN; i++)
		{
			if (mMap[i][1] > 90)
			{
				mKeybit |= (1 << (mMap[i][1] - 97));
				mMap[i][1] = '.';
			}
			else if (mMap[i][1] == '$')
			{
				mMoney++;
				mMap[i][1] = '.';
			}
			if (mMap[i][mM] > 90)
			{
				mKeybit |= (1 << (mMap[i][mM] - 97));
				mMap[i][mM] = '.';
			}
			else if (mMap[i][mM] == '$')
			{
				mMoney++;
				mMap[i][mM] = '.';
			}
		}

		Updating();
	}

	void Do()
	{
		int num = 0;
		int tmpsizeof = sizeof(bool) * (mM + 2);
		while (mbAlterflag)
		{
			mbAlterflag = false;
			bool** Check = new bool* [mN + 2];
			for (int i = 0; i < mN + 2; i++)
			{
				Check[i] = new bool[mM + 2];
				memset(Check[i], false, tmpsizeof);
			}

			for (int j = 2; j < mM; j++)
			{
				if (mMap[1][j] == '.' && !Check[1][j])
				{
					Thievery(1, j, Check);
				}
				if (mMap[mN][j] == '.' && !Check[mN][j])
				{
					Thievery(mN, j, Check);
				}
			}

			for (int i = 2; i < mN; i++)
			{
				if (mMap[i][1] == '.' && !Check[i][1])
				{
					Thievery(i, 1, Check);
				}
				if (mMap[i][mM] == '.' && !Check[i][mM])
				{
					Thievery(i, mM, Check);
				}
			}

			for (int i = 0; i < mN + 2; i++)
				delete[] Check[i];
			delete[] Check;

			Updating();
		}
	}

	void Printmoney()
	{
		printf("%d\n", mMoney);
	}

private:
	void Updating()
	{
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				if (mMap[i][j] < 36 && (mKeybit & (1 << mMap[i][j])))
				{
					mMap[i][j] = '.';
					if (!mbAlterflag)
						mbAlterflag = true;
				}
			}
		}
	}

	void Thievery(int n, int m, bool** mCheck)
	{
		mCheck[n][m] = true;
		std::queue<pi> BFSbox;
		BFSbox.push({ n,m });
		while (!BFSbox.empty())
		{
			//BFSbox.front().first = nown, second() = nowm

			mCheck[nown][nowm] = true;
			for (int i = 0; i < 4; i++)
			{
				int nextN = nown + nextnarr[i], nextM = nowm + nextmarr[i];
				char nextC = mMap[nextN][nextM];
				if (!mCheck[nextN][nextM])
				{
					mCheck[nextN][nextM] = true;

					if (nextC == '*')
						continue;
					else if (nextC == '.')
						BFSbox.push({ nextN,nextM });
					else if (nextC == '$')
					{
						mMoney++;
						mMap[nextN][nextM] = '.';
						BFSbox.push({ nextN,nextM });
					}
					else if (nextC < 32)
					{
						if (mKeybit & (1 << nextC))
						{
							mMap[nextN][nextM] = '.';
							BFSbox.push({ nextN,nextM });
						}
					}
					else
					{
						mKeybit |= (1 << (nextC - 97));
						mMap[nextN][nextM] = '.';
						BFSbox.push({ nextN,nextM });
					}

				}
			}

			BFSbox.pop();
		}

	}

private:
	vvc mMap;
	int nextnarr[4] = { 0,0,1,-1 }, nextmarr[4] = { 1,-1,0,0 };
	int mN, mM, mMoney = 0;
	int mKeybit = 0;
	bool mbAlterflag = true;
};

void Solve()
{
	Thief thief;
	thief.Do();
	thief.Printmoney();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
		Solve();

	return 0;
}