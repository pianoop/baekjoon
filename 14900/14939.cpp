//불 끄기
//-------------------------------------------------------------------
#include <iostream>
#include <cstring>

class SwitchOff
{
public:
	SwitchOff()
	{
		for (int i = 0; i < 12; i++)
			memset(mArr[i], false, sizeof(bool) * 12);
		input();
	}

	int PrintAns()
	{
		if (mAns = -2)
			calc();

		return mAns;
	}

private:
	void input()
	{
		char tmp;
		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 11; j++)
			{
				std::cin >> tmp;
				if (tmp == 79)
					mArr[i][j] = true;
			}
		}
	}

	void calc()
	{
		int min = 0x7FFFFFFF;
		
		for (int casebit = 0; casebit < (1 << 10); casebit++)
		{
			int cnt = 0;
			bool cpy[12][12];
			memcpy(cpy, mArr, sizeof(bool) * 12 * 12);

			for (int first = 0; first < 10; first++)
			{
				if (casebit & (1 << first))
				{
					cnt++;
					push(1, first + 1, cpy);
				}
			}

			for (int i = 2; i < 11; i++)
			{
				for (int j = 1; j < 11; j++)
				{
					if (cpy[i - 1][j])
					{
						cnt++;
						push(i, j, cpy);
					}
				}
			}

			bool continueflag = false;
			for (int end = 1; end < 11; end++)
			{
				if (cpy[10][end])
				{
					continueflag = true;
					break;
				}
			}
			if (continueflag)
				continue;

			min = std::min(min, cnt);
		}

		if (min == 0x7FFFFFFF)
			mAns = -1;
		else
			mAns = min;
	}

	void push(int a, int b, bool cpy[][12])
	{
		if (cpy[a][b])
			cpy[a][b] = false;
		else
			cpy[a][b] = true;

		if (cpy[a][b - 1])
			cpy[a][b - 1] = false;
		else
			cpy[a][b - 1] = true;

		if (cpy[a][b + 1])
			cpy[a][b + 1] = false;
		else
			cpy[a][b + 1] = true;

		if (cpy[a - 1][b])
			cpy[a - 1][b] = false;
		else
			cpy[a - 1][b] = true;

		if (cpy[a + 1][b])
			cpy[a + 1][b] = false;
		else
			cpy[a + 1][b] = true;
	}

private:
	bool mArr[12][12];
	int mAns = -2;
};

void Solve()
{
	SwitchOff test;
	printf("%d", test.PrintAns());
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}