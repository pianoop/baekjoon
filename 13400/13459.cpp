//구슬 탈출
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

class Marblegame
{
public:
	Marblegame(int n, int m) :mN(n), mM(m)
	{
		mTable.resize(mN, vc(mM));
		pi b, r;
		input(b, r);

		computeRecur(1, b, r);
	}

	void PrintMin()
	{
		if (mMin == 11)
			printf("0");
		else
			printf("1");
	}

private:
	void input(pi& b, pi& r)
	{
		for (int i = 0; i < mN; i++)
		{
			for (int j = 0; j < mM; j++)
			{
				std::cin >> mTable[i][j];
				if (mTable[i][j] == 'B')
				{
					b.first = i;
					b.second = j;
					mTable[i][j] = '.';
				}
				if (mTable[i][j] == 'R')
				{
					r.first = i;
					r.second = j;
					mTable[i][j] = '.';
				}
			}
		}
	}

	void computeRecur(int cnt, pi b, pi r)
	{
		if (cnt == 11 || cnt >= mMin)
			return;

		int tmpr, tmpb;
		if (r.second < b.second) //left
		{
			mTable[b.first][b.second] = 0;

			tmpr = r.second;
			while (mTable[r.first][tmpr - 1] == '.')
				tmpr--;
			if (mTable[r.first][tmpr - 1] == 'O')
				tmpr--;

			mTable[b.first][b.second] = '.';

			if (mTable[r.first][tmpr] != 'O')
			{
				mTable[r.first][tmpr] = 0;

				tmpb = b.second;
				while (mTable[b.first][tmpb - 1] == '.')
					tmpb--;
				if (mTable[b.first][tmpb - 1] == 'O')
					tmpb--;

				mTable[r.first][tmpr] = '.';

				if (mTable[b.first][tmpb] != 'O')
					computeRecur(cnt + 1, { b.first,tmpb }, { r.first,tmpr });
			}
			else
			{
				tmpb = b.second;
				while (mTable[b.first][tmpb - 1] == '.')
					tmpb--;

				if (mTable[b.first][tmpb - 1] != 'O')
				{
					mMin = cnt;
					return;
				}
			}
		}
		else
		{
			mTable[r.first][r.second] = 0;

			tmpb = b.second;
			while (mTable[b.first][tmpb - 1] == '.')
				tmpb--;
			if (mTable[b.first][tmpb - 1] == 'O')
				tmpb--;

			mTable[r.first][r.second] = '.';

			if (mTable[b.first][tmpb] != 'O')
			{
				mTable[b.first][tmpb] = 0;

				tmpr = r.second;
				while (mTable[r.first][tmpr - 1] == '.')
					tmpr--;
				if (mTable[r.first][tmpr - 1] == 'O')
					tmpr--;

				mTable[b.first][tmpb] = '.';

				if (mTable[r.first][tmpr] != 'O')
					computeRecur(cnt + 1, { b.first,tmpb }, { r.first,tmpr });
				else
				{
					mMin = cnt;
					return;
				}
			}
		}

		if (r.second > b.second) //right
		{
			mTable[b.first][b.second] = 0;

			tmpr = r.second;
			while (mTable[r.first][tmpr + 1] == '.')
				tmpr++;
			if (mTable[r.first][tmpr + 1] == 'O')
				tmpr++;

			mTable[b.first][b.second] = '.';

			if (mTable[r.first][tmpr] != 'O')
			{
				mTable[r.first][tmpr] = 0;

				tmpb = b.second;
				while (mTable[b.first][tmpb + 1] == '.')
					tmpb++;
				if (mTable[b.first][tmpb + 1] == 'O')
					tmpb++;

				mTable[r.first][tmpr] = '.';

				if (mTable[b.first][tmpb] != 'O')
					computeRecur(cnt + 1, { b.first,tmpb }, { r.first,tmpr });
			}
			else
			{
				tmpb = b.second;
				while (mTable[b.first][tmpb + 1] == '.')
					tmpb++;

				if (mTable[b.first][tmpb + 1] != 'O')
				{
					mMin = cnt;
					return;
				}
			}
		}
		else
		{
			mTable[r.first][r.second] = 0;

			tmpb = b.second;
			while (mTable[b.first][tmpb + 1] == '.')
				tmpb++;
			if (mTable[b.first][tmpb + 1] == 'O')
				tmpb++;

			mTable[r.first][r.second] = '.';

			if (mTable[b.first][tmpb] != 'O')
			{
				mTable[b.first][tmpb] = 0;

				tmpr = r.second;
				while (mTable[r.first][tmpr + 1] == '.')
					tmpr++;
				if (mTable[r.first][tmpr + 1] == 'O')
					tmpr++;

				mTable[b.first][tmpb] = '.';

				if (mTable[r.first][tmpr] != 'O')
					computeRecur(cnt + 1, { b.first,tmpb }, { r.first,tmpr });
				else
				{
					mMin = cnt;
					return;
				}
			}
		}

		if (r.first < b.first) //up
		{
			mTable[b.first][b.second] = 0;

			tmpr = r.first;
			while (mTable[tmpr - 1][r.second] == '.')
				tmpr--;
			if (mTable[tmpr - 1][r.second] == 'O')
				tmpr--;

			mTable[b.first][b.second] = '.';

			if (mTable[tmpr][r.second] != 'O')
			{
				mTable[tmpr][r.second] = 0;

				tmpb = b.first;
				while (mTable[tmpb - 1][b.second] == '.')
					tmpb--;
				if (mTable[tmpb - 1][b.second] == 'O')
					tmpb--;

				mTable[tmpr][r.second] = '.';

				if (mTable[tmpb][b.second] != 'O')
					computeRecur(cnt + 1, { tmpb,b.second }, { tmpr,r.second });
			}
			else
			{
				tmpb = b.first;
				while (mTable[tmpb - 1][b.second] == '.')
					tmpb--;

				if (mTable[tmpb - 1][b.second] != 'O')
				{
					mMin = cnt;
					return;
				}
			}
		}
		else
		{
			mTable[r.first][r.second] = 0;

			tmpb = b.first;
			while (mTable[tmpb - 1][b.second] == '.')
				tmpb--;
			if (mTable[tmpb - 1][b.second] == 'O')
				tmpb--;

			mTable[r.first][r.second] = '.';

			if (mTable[tmpb][b.second] != 'O')
			{
				mTable[tmpb][b.second] = 0;

				tmpr = r.first;
				while (mTable[tmpr - 1][r.second] == '.')
					tmpr--;
				if (mTable[tmpr - 1][r.second] == 'O')
					tmpr--;

				mTable[tmpb][b.second] = '.';

				if (mTable[tmpr][r.second] != 'O')
					computeRecur(cnt + 1, { tmpb,b.second }, { tmpr,r.second });
				else
				{
					mMin = cnt;
					return;
				}
			}
		}

		if (r.first > b.first) //down
		{
			mTable[b.first][b.second] = 0;

			tmpr = r.first;
			while (mTable[tmpr + 1][r.second] == '.')
				tmpr++;
			if (mTable[tmpr + 1][r.second] == 'O')
				tmpr++;

			mTable[b.first][b.second] = '.';

			if (mTable[tmpr][r.second] != 'O')
			{
				mTable[tmpr][r.second] = 0;

				tmpb = b.first;
				while (mTable[tmpb + 1][b.second] == '.')
					tmpb++;
				if (mTable[tmpb + 1][b.second] == 'O')
					tmpb++;

				mTable[tmpr][r.second] = '.';

				if (mTable[tmpb][b.second] != 'O')
					computeRecur(cnt + 1, { tmpb,b.second }, { tmpr,r.second });
			}
			else
			{
				tmpb = b.first;
				while (mTable[tmpb + 1][b.second] == '.')
					tmpb++;

				if (mTable[tmpb + 1][b.second] != 'O')
				{
					mMin = cnt;
					return;
				}
			}
		}
		else
		{
			mTable[r.first][r.second] = 0;

			tmpb = b.first;
			while (mTable[tmpb + 1][b.second] == '.')
				tmpb++;
			if (mTable[tmpb + 1][b.second] == 'O')
				tmpb++;

			mTable[r.first][r.second] = '.';

			if (mTable[tmpb][b.second] != 'O')
			{
				mTable[tmpb][b.second] = 0;

				tmpr = r.first;
				while (mTable[tmpr + 1][r.second] == '.')
					tmpr++;
				if (mTable[tmpr + 1][r.second] == 'O')
					tmpr++;

				mTable[tmpb][b.second] = '.';

				if (mTable[tmpr][r.second] != 'O')
					computeRecur(cnt + 1, { tmpb,b.second }, { tmpr,r.second });
				else
				{
					mMin = cnt;
					return;
				}
			}
		}

	}

private:
	int mN, mM, mMin = 11;
	vvc mTable;
};

void Solve()
{
	int N, M;
	std::cin >> N >> M;
	Marblegame game(N, M);
	game.PrintMin();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}