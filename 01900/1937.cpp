//욕심쟁이 판다
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int nextR[4] = { 0,0,1,-1 };
int nextC[4] = { 1,-1,0,0 };

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
			for (int j = 1; j < mN; j++)
			{
				if (mDp[i][j] == -1)
				{
					mDp[i][j] = 0;
					recur(i, j);

					Max = std::max(Max, mDp[i][j]);
				}
			}
		}

		std::cout << Max;
	}


private:
	void input()
	{
		std::cin >> mN;
		mN += 2;
		mMap.resize(mN, vi(mN));
		mDp.resize(mN, vi(mN, -1));
		mN--;

		for (int i = 1; i < mN; i++)
			for (int j = 1; j < mN; j++)
				std::cin >> mMap[i][j];
	}

	void recur(int r, int c)
	{
		int nr, nc, &nowM = mMap[r][c], &nowDp = mDp[r][c];
		for (int i = 0; i < 4; i++)
		{
			nr = r + nextR[i], nc = c + nextC[i];

			if (mMap[nr][nc] > nowM)
			{
				if (mDp[nr][nc] == -1)
				{
					mDp[nr][nc] = 0;
					recur(nr, nc);
				}

				nowDp = std::max(nowDp, mDp[nr][nc]);
			}
		}

		nowDp++;
	}


private:
	vvi mMap, mDp;
	int mN;

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