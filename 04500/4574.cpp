//스도미노쿠
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;

int nextN[4] = { 0, 0, 1, -1 };
int nextM[4] = { 1, -1, 0, 0 };

class Tri
{
public:
	int a, b;
	bool check;
};

class Sudo
{
public:
	Sudo(int N)
	{
		mM -= N;
		input(N);
		solve();
	}


private:
	void input(int D)
	{
		bool bPair[10][10];
		memset(bPair, false, sizeof(bPair));
		memset(mbCol, false, sizeof(mbCol));
		memset(mbRow, false, sizeof(mbRow));
		memset(mbSq, false, sizeof(mbSq));

		for (int i = 1; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
				bPair[i][j] = true;
		}

		char nc;
		int a, b, m, n;
		while (D--)
		{
			std::cin >> a >> nc >> m >> b;
			if (a < b)
				bPair[a][b] = false;
			else
				bPair[b][a] = false;

			n = nc - 65;
			m--;
			mMap[n][m] = a;
			mbRow[n][a] = true;
			mbCol[m][a] = true;
			mbSq[n / 3][m / 3][a] = true;

			std::cin >> nc >> m;
			n = nc - 65;
			m--;
			mMap[n][m] = b;
			mbRow[n][b] = true;
			mbCol[m][b] = true;
			mbSq[n / 3][m / 3][b] = true;
		}

		for (int i = 1; i < 10; i++)
		{
			std::cin >> nc >> m;
			n = nc - 65;
			m--;
			mMap[n][m] = i;
			mbRow[n][i] = true;
			mbCol[m][i] = true;
			mbSq[n / 3][m / 3][i] = true;
		}

		for (int i = 1; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (bPair[i][j])
					mDomin.push_back(Tri(i, j, true));
			}
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (mMap[i][j] == 0)
					mBlank.push_back({ i,j });
			}
		}

		//mMap 테두리 처리
		for (int i = 0; i < 9; i++)
			mMap[9][i] = mMap[i][9] = -1;
	}

	void solve()
	{
		recur(0, 0);

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				std::cout << mMap[i][j];
			std::cout << "\n";
		}
	}

	void recur(int now, int i)
	{
		if (now == mM)
		{
			mbEND = true;
			return;
		}

		int next = now + 1;
		
		for (; i < 72; i++)
		{
			auto& [n, m] = mBlank[i];
			if (mMap[n][m] == 0)
			{
				int nn = n / 3, mm = m / 3, n1 = n + 1, m1 = m + 1;
				int	n1n = n1/3, m1m = m1/3, nexti = i + 1;

				for (auto& [a, b, check] : mDomin)
				{
					if (check)
					{
						//std::cout << n << "||" << m << "||" << a << "||" << b << "\n";
						check = false;
						//mMap[n][m]에 a가 올 때
						if (!mbRow[n][a] && !mbCol[m][a] && !mbSq[nn][mm][a])
						{
							mMap[n][m] = a;
							mbRow[n][a] = mbCol[m][a] = mbSq[nn][mm][a] = true;

							if (mMap[n][m1] == 0 && !mbRow[n][b] && !mbCol[m1][b] && !mbSq[nn][m1m][b])
							{
								mbRow[n][b] = mbCol[m1][b] = mbSq[nn][m1m][b] = true;
								mMap[n][m1] = b;

								recur(next, nexti);
								if (mbEND)
									return;

								mMap[n][m1] = 0;
								mbRow[n][b] = mbCol[m1][b] = mbSq[nn][m1m][b] = false;
							}

							if (mMap[n1][m] == 0 && !mbRow[n1][b] && !mbCol[m][b] && !mbSq[n1n][mm][b])
							{
								mbRow[n1][b] = mbCol[m][b] = mbSq[n1n][mm][b] = true;
								mMap[n1][m] = b;

								recur(next, nexti);
								if (mbEND)
									return;

								mMap[n1][m] = 0;
								mbRow[n1][b] = mbCol[m][b] = mbSq[n1n][mm][b] = false;
							}

							mbRow[n][a] = mbCol[m][a] = mbSq[nn][mm][a] = false;
							mMap[n][m] = 0;
						}
						//mMap[n][m]에 b가 올 때
						if (!mbRow[n][b] && !mbCol[m][b] && !mbSq[nn][mm][b])
						{
							mMap[n][m] = b;
							mbRow[n][b] = mbCol[m][b] = mbSq[nn][mm][b] = true;

							if (mMap[n][m1] == 0 && !mbRow[n][a] && !mbCol[m1][a] && !mbSq[nn][m1m][a])
							{
								mbRow[n][a] = mbCol[m1][a] = mbSq[nn][m1m][a] = true;
								mMap[n][m1] = a;

								recur(next, nexti);
								if (mbEND)
									return;

								mMap[n][m1] = 0;
								mbRow[n][a] = mbCol[m1][a] = mbSq[nn][m1m][a] = false;
							}

							if (mMap[n1][m] == 0 && !mbRow[n1][a] && !mbCol[m][a] && !mbSq[n1n][mm][a])
							{
								mbRow[n1][a] = mbCol[m][a] = mbSq[n1n][mm][a] = true;
								mMap[n1][m] = a;

								recur(next, nexti);
								if (mbEND)
									return;

								mMap[n1][m] = 0;
								mbRow[n1][a] = mbCol[m][a] = mbSq[n1n][mm][a] = false;
							}

							mbRow[n][b] = mbCol[m][b] = mbSq[nn][mm][b] = false;
							mMap[n][m] = 0;
						}

						check = true;
					}
				}

				return;
			}
		}
	}

private:
	std::vector<Tri> mDomin;
	std::vector<pi> mBlank;
	int mMap[10][10] = { 0, };
	int mM = 36;
	bool mbCol[9][10], mbRow[9][10], mbSq[3][3][10];
	bool mbEND = false;

};

void Solve()
{
	int N, cnt = 1;
	while (true)
	{
		std::cin >> N;
		if (N == 0)
			break;
		std::cout << "Puzzle " << cnt++ << "\n";
		Sudo nm(N);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}