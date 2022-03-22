//피리 부는 사나이
//
#include <iostream>
#include <vector>
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class SafeZone
{
public:
	SafeZone()
	{
		input();
	}

	void PrintAns()
	{
		int groupNum = 0, order = 0;
		vvi check(mN, vi(mM));

		for (int i = 0; i < mN; i++)
		{
			for (int j = 0; j < mM; j++)
			{
				if(check[i][j]==0)
				{
					check[i][j] = ++order;
					int nowN = i, nowM = j;
					while (true)
					{
						switch (mTable[nowN][nowM])
						{
						case 'D':
							nowN++;
							break;
						case 'U':
							nowN--;
							break;
						case 'L':
							nowM--;
							break;
						default:  // 'R'
							nowM++;
						}

						if (check[nowN][nowM] == 0)
							check[nowN][nowM] = order;
						else if (check[nowN][nowM] == order)
						{
							groupNum++;
							break;
						}
						else
							break;
					}
				}
			}
		}

		printf("%d", groupNum);
	}

private:
	void input()
	{
		std::cin >> mN >> mM;
		mTable.resize(mN, vc(mM));
		for (int i = 0; i < mN; i++)
			for (int j = 0; j < mM; j++)
				std::cin >> mTable[i][j];
	}


private:
	vvc mTable;
	int mN, mM;
};

void Solve()
{
	SafeZone safe;
	safe.PrintAns();

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}