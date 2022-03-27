//합성함수와 쿼리
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class SparseTable
{
public:
	SparseTable()
	{
		input();
		setTable();
	}

	void PrintAns()
	{
		int n, now;
		std::cin >> n >> now;
		
		for (int k = 18; k >= 0; k--)
		{
			if (n & 1 << k)
				now = mTable[k][now];
		}

		std::cout << now << "\n";
	}

private:
	void input()
	{

		std::cin >> mN;
		int tmp = mN + 1;
		for (int i = 0; i < 19; i++)
			mTable[i].resize(tmp);

		for (int j = 1; j <= mN; j++)
		{
			std::cin >> mTable[0][j];
		}
	}

	void setTable()
	{
		for (int i = 1; i < 19; i++)
		{
			for (int j = 1; j <= mN; j++)
			{
				mTable[i][j] = mTable[i - 1][mTable[i - 1][j]];
			}
		}
	}

private:
	vi mTable[19];
	int mN;

};

void Solve()
{
	SparseTable ST;

	int Q;
	std::cin >> Q;

	while (Q--)
		ST.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}