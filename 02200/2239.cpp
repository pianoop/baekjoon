//스도쿠
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

class Triple
{
public:
	Triple(int a, int b) :mR(a), mC(b), mS(a / 3 + (b / 3) * 3) {}

	int mR, mC, mS;
};

class Sdk
{
public:
	Sdk()
	{
		std::string str;
		mZeros.reserve(81);
		for (int i = 0; i < 9; i++)
		{
			std::cin >> str;
			for (int j = 0; j < 9; j++)
			{
				int tmp = str[j] - 48;
				if (tmp == 0)
				{
					mZeros.emplace_back(Triple(i, j));
				}
				else
				{
					mRow[i][tmp] = true;
					mCol[j][tmp] = true;
					mSquare[i / 3 + (j / 3) * 3][tmp] = true;
					mSdkarr[i][j] = tmp;
				}
			}
		}
	}

	void Sortsdk()
	{
		if (!mZeros.empty())
			Sortsdk_sub(0);
	}

	void PrintSdk()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d", mSdkarr[i][j]);
			}
			printf("\n");
		}
	}

private:
	void Sortsdk_sub(int zeroidx)
	{
		if (zeroidx == int(mZeros.size()))
			flag = 1;
		else
		{
			int& i = mZeros[zeroidx].mR;
			int& j = mZeros[zeroidx].mC;
			int& s = mZeros[zeroidx].mS;

			for (int k = 1; k < 10; k++)
			{
				if (!mRow[i][k] && !mCol[j][k] && !mSquare[s][k])
				{
					mSdkarr[i][j] = k;
					mRow[i][k] = true;
					mCol[j][k] = true;
					mSquare[s][k] = true;

					Sortsdk_sub(zeroidx + 1);
					if (flag)
						return;

					mRow[i][k] = false;
					mCol[j][k] = false;
					mSquare[s][k] = false;
				}
			}
			mSdkarr[i][j] = 0;
		}
	}


	bool flag = 0;
	bool mRow[9][10] = { 0, }, mCol[9][10] = { 0, }, mSquare[9][10] = { 0, };
	int mSdkarr[9][9] = { 0, };
	std::vector<Triple> mZeros;
};

void Solve()
{
	Sdk sdk;
	sdk.Sortsdk();
	sdk.PrintSdk();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}
