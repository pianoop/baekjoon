//벽 부수고 이동하기 4
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class BreakWall
{
public:
	BreakWall()
	{
		input();
	}

	void PrintAns()
	{
		calc();

		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				printf("%d", mMap[i][j] % 10);
			}
			printf("\n");
		}
	}

private:
	void input()
	{
		std::cin >> mN >> mM;
		mMap.resize(mN + 2, vi(mM + 2, -1));

		char tmp;
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				std::cin >> tmp;
				if (tmp == 49)
					mMap[i][j] = 1;
				else
					mMap[i][j] = 0;
			}
		}
	}

	void calc()
	{
		vvi check = mMap;
		int order = 1;
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				if (check[i][j] == 0)
				{
					order++;
					check[i][j] = -1;
					std::stack<std::pair<int, int> > wall;
					std::queue<std::pair<int, int> > bfsbox;
					bfsbox.push({ i,j });
					int blockNum = 0;

					while (!bfsbox.empty())
					{
						blockNum++;
						int nowN = bfsbox.front().first, nowM = bfsbox.front().second;
						bfsbox.pop();

						int tmpN = nowN + 1, tmpM = nowM;
						if (check[tmpN][tmpM] >= 0)
						{
							if (mMap[tmpN][tmpM] == 0)
							{
								bfsbox.push({ tmpN, tmpM });
								check[tmpN][tmpM] = -1;
							}
							else if (check[tmpN][tmpM] != order)
							{
								wall.push({ tmpN, tmpM });
								check[tmpN][tmpM] = order;
							}
						}

						tmpN = nowN - 1;
						if (check[tmpN][tmpM] >= 0)
						{
							if (mMap[tmpN][tmpM] == 0)
							{
								bfsbox.push({ tmpN, tmpM });
								check[tmpN][tmpM] = -1;
							}
							else if (check[tmpN][tmpM] != order)
							{
								wall.push({ tmpN, tmpM });
								check[tmpN][tmpM] = order;
							}
						}

						tmpN = nowN, tmpM = nowM + 1;
						if (check[tmpN][tmpM] >= 0)
						{
							if (mMap[tmpN][tmpM] == 0)
							{
								bfsbox.push({ tmpN, tmpM });
								check[tmpN][tmpM] = -1;
							}
							else if (check[tmpN][tmpM] != order)
							{
								wall.push({ tmpN, tmpM });
								check[tmpN][tmpM] = order;
							}
						}

						tmpM = nowM - 1;
						if (check[tmpN][tmpM] >= 0)
						{
							if (mMap[tmpN][tmpM] == 0)
							{
								bfsbox.push({ tmpN, tmpM });
								check[tmpN][tmpM] = -1;
							}
							else if (check[tmpN][tmpM] != order)
							{
								wall.push({ tmpN, tmpM });
								check[tmpN][tmpM] = order;
							}
						}

					}

					while (!wall.empty())
					{
						mMap[wall.top().first][wall.top().second] += blockNum;
						wall.pop();
					}
				}
			}
		}
	}



private:
	vvi mMap;
	int mN, mM;
};

void Solve()
{
	BreakWall wall;
	wall.PrintAns();

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}