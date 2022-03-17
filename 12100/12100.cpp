//2048 (Easy)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Game2048
{
public:
	Game2048(int n) :mN(n)
	{
		mTable.resize(n + 2, vi(n + 2));
		Input();
	}

	void PrintMax()
	{
		if (mMax == 0)
			ComputeRecur(0, mTable);
		printf("%d", mMax);
	}

private:
	void Input()
	{
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mN; j++)
			{
				std::cin >> mTable[i][j];
			}
		}
	}

	void ComputeRecur(int cnt, const vvi& table)
	{
		if (cnt == 5)
		{
			UpdatingMax(table);
			return;
		}
		vvi tmptable(mN + 2, vi(mN + 2));

		//left
		for (int i = 1; i <= mN; i++)
		{
			int tmpj = 1;
			int j = 1;
			while (j <= mN)
			{
				if (table[i][j] == 0)
				{
					j++;
					continue;
				}

				int nextj = j + 1;
				while (nextj <= mN)
				{
					if (table[i][nextj] == 0)
						nextj++;
					else
						break;
				}

				if (table[i][j] == table[i][nextj])
				{
					tmptable[i][tmpj] = table[i][j] << 1;
					j = nextj + 1;
				}
				else
				{
					tmptable[i][tmpj] = table[i][j];
					j = nextj;
				}
				tmpj++;
			}
			while (tmpj <= mN)
				tmptable[i][tmpj++] = 0;
		}
		ComputeRecur(cnt + 1, tmptable);

		//right
		for (int i = 1; i <= mN; i++)
		{
			int tmpj = mN;
			int j = mN;
			while (j > 0)
			{
				if (table[i][j] == 0)
				{
					j--;
					continue;
				}

				int nextj = j - 1;
				while (nextj > 0)
				{
					if (table[i][nextj] == 0)
						nextj--;
					else
						break;
				}

				if (table[i][j] == table[i][nextj])
				{
					tmptable[i][tmpj] = table[i][j] << 1;
					j = nextj - 1;
				}
				else
				{
					tmptable[i][tmpj] = table[i][j];
					j = nextj;
				}
				tmpj--;
			}
			while (tmpj > 0)
				tmptable[i][tmpj--] = 0;
		}
		ComputeRecur(cnt + 1, tmptable);

		//up
		for (int j = 1; j <= mN; j++)
		{
			int tmpi = 1;
			int i = 1;
			while (i <= mN)
			{
				if (table[i][j] == 0)
				{
					i++;
					continue;
				}

				int nexti = i + 1;
				while (nexti <= mN)
				{
					if (table[nexti][j] == 0)
						nexti++;
					else
						break;
				}

				if (table[i][j] == table[nexti][j])
				{
					tmptable[tmpi][j] = table[i][j] << 1;
					i = nexti + 1;
				}
				else
				{
					tmptable[tmpi][j] = table[i][j];
					i = nexti;
				}
				tmpi++;
			}
			while (tmpi <= mN)
				tmptable[tmpi++][j] = 0;
		}
		ComputeRecur(cnt + 1, tmptable);

		//down
		for (int j = 1; j <= mN; j++)
		{
			int tmpi = mN;
			int i = mN;
			while (i > 0)
			{
				if (table[i][j] == 0)
				{
					i--;
					continue;
				}

				int nexti = i - 1;
				while (nexti > 0)
				{
					if (table[nexti][j] == 0)
						nexti--;
					else
						break;
				}

				if (table[i][j] == table[nexti][j])
				{
					tmptable[tmpi][j] = table[i][j] << 1;
					i = nexti - 1;
				}
				else
				{
					tmptable[tmpi][j] = table[i][j];
					i = nexti;
				}
				tmpi--;
			}
			while (tmpi > 0)
				tmptable[tmpi--][j] = 0;
		}
		ComputeRecur(cnt + 1, tmptable);
	}

	void UpdatingMax(const vvi& table)
	{
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mN; j++)
			{
				if (mMax < table[i][j])
					mMax = table[i][j];
			}
		}
	}

private:
	int mN, mMax = 0;
	vvi mTable;
};

void Solve()
{
	int N;
	std::cin >> N;
	Game2048 game(N);
	game.PrintMax();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}