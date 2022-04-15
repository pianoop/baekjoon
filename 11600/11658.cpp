//구간 합 구하기 3
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Fenwick
{
public:
	Fenwick(int n) :mN(n)
	{
		input();
	}

	void Query(int m)
	{
		int q, a1, b1, a2, b2;
		while (m--)
		{
			std::cin >> q;
			if (q == 0)
			{
				std::cin >> a1 >> b1 >> a2;
				update(a1, b1, a2 - sum(a1, b1, a1, b1));
			}
			else
			{
				std::cin >> a1 >> b1 >> a2 >> b2;
				std::cout << sum_sub(a2, b2) - sum_sub(a2, b1 - 1) - sum_sub(a1 - 1, b2) + sum_sub(a1 - 1, b1 - 1) << "\n";
			}
		}
	}

private:
	void input()
	{
		mN++; //------------------------------------------------
		mFenwick.resize(mN);

		for (int i = 1; i < mN; i++)
		{
			mFenwick[i].resize(mN);
			for (int j = 1; j < mN; j++)
				std::cin >> mFenwick[i][j];

			for (int j = 1; j < mN; ++j)
			{
				if (j + (j & -j) < mN)
					mFenwick[i][j + (j & -j)] += mFenwick[i][j];
			}
		}

		for (int j = 1; j < mN; ++j) 
		{
			for (int i = 1; i < mN; ++i) 
			{
				if (i + (i & -i) < mN)
					mFenwick[i + (i & -i)][j] += mFenwick[i][j];
			}
		}

		mN--; //------------------------------------------------
	}

	inline void update(int a, int b, int value)
	{
		for (int i = a; i <= mN; i += (i & -i))
			for (int j = b; j <= mN; j += (j & -j))
				mFenwick[i][j] += value;
	}

	inline int sum(int a1, int b1, int a2, int b2)
	{
		return sum_sub(a2, b2) - sum_sub(a2, b1 - 1) - sum_sub(a1 - 1, b2) + sum_sub(a1 - 1, b1 - 1);
	}

	inline int sum_sub(int a, int b)
	{
		int ans = 0;
		for (int i = a; i > 0; i -= (i & -i))
			for (int j = b; j > 0; j -= (j & -j))
				ans += mFenwick[i][j];

		return ans;
	}


private:
	vvi mFenwick;
	int mN;

};


void Solve()
{
	int N, M;
	std::cin >> N >> M;

	Fenwick fen(N);
	fen.Query(M);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}