//사다리 조작
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

class Ladder
{
public:
	Ladder()
	{
		input();
	}

	~Ladder()
	{
		for (int i = 0; i <= mN; i++)
			delete[] mbRight[i];
		delete[] mbRight;
	}

	void Calc()
	{
		for (; mMin < 4; mMin++)
		{
			search(1, 0, 0, mMin);

			if (mbFlag)
				return;
		}
	}

	void PrintAns()
	{
		if (mMin > 3)
			std::cout << "-1";
		else
			std::cout << mMin;
	}

private:
	void input()
	{
		int e;
		std::cin >> mN >> e >> mM;
		mmN = mN - 1;
		mM++, mN++; // 주의1

		mbRight = new bool* [mN];
		for (int i = 0; i < mN; i++)
		{
			mbRight[i] = new bool[mM];
			memset(mbRight[i], false, sizeof(bool) * mM);
		}
		
		mN--; //주의2, mN, mM은 여기가 끝

		int h, l;
		while (e--)
		{
			std::cin >> h >> l;
			mbRight[l][h] = true;
		}
	}

	void search(int i0, int j0, int num, const int N)
	{
		if (num == N)
		{
			mbFlag = check();
			return;
		}

		num++;

		for (int j = j0 + 1; j < mM; j++)
		{
			if (!mbRight[i0][j] && (i0 == 1 || !mbRight[i0 - 1][j]) && (i0 == mmN || !mbRight[i0 + 1][j]))
			{
				mbRight[i0][j] = true;
				search(i0, j, num, N);
				mbRight[i0][j] = false;

				if (mbFlag)
					return;
			}
		}

		for (int i = i0 + 1; i <= mmN; i++)
		{
			for (int j = 1; j < mM; j++)
			{
				if (!mbRight[i][j] && (i == 1 || !mbRight[i - 1][j]) && (i == mmN || !mbRight[i + 1][j]))
				{
					mbRight[i][j] = true;
					search(i, j, num, N);
					mbRight[i][j] = false;

					if (mbFlag)
						return;
				}
			}
		}
	}

	bool check()
	{
		for (int i = 1; i <= mN; i++)
		{
			int now = i;
			for (int j = 1; j < mM; j++)
			{
				if (mbRight[now - 1][j])
					now--;
				else if (mbRight[now][j])
					now++;
			}

			if (i != now)
				return false;
		}

		return true;
	}


private:
	bool mbFlag = false;
	bool **mbRight;
	int mN, mmN, mM, mMin = 0;
};

void Solve()
{
	Ladder ladder;
	ladder.Calc();
	ladder.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}