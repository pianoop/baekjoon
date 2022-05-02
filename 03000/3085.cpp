//사탕 게임
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;

class Candy
{
public:
	Candy()
	{
		input();
		solve();
	}

private:
	void input()
	{
		std::cin >> mN;
		mMap.resize(mN + 2, vc(mN + 2));

		for (int i = 1; i <= mN; i++)
			for (int j = 1; j <= mN; j++)
				std::cin >> mMap[i][j];
	}

	void solve()
	{
		for (int i = 1; i < mN; i++)
		{
			for (int j = 1; j < mN; j++)
			{

				std::swap(mMap[i][j], mMap[i][j + 1]);
				search(i, j);
				search(i, j + 1);
				std::swap(mMap[i][j], mMap[i][j + 1]);

				std::swap(mMap[i][j], mMap[i + 1][j]);
				search(i, j);
				search(i + 1, j);
				std::swap(mMap[i][j], mMap[i + 1][j]);
			}

			std::swap(mMap[i][mN], mMap[i + 1][mN]);
			search(i, mN);
			search(i + 1, mN);
			std::swap(mMap[i][mN], mMap[i + 1][mN]);
		}

		for (int j = 1; j < mN; j++)
		{
			std::swap(mMap[mN][j], mMap[mN][j + 1]);
			search(mN, j);
			search(mN, j + 1);
			std::swap(mMap[mN][j], mMap[mN][j + 1]);
		}

		std::cout << mMax;
	}

	void search(int i, int j)
	{
		char C = mMap[i][j];
		int total = 1, tmp;

		tmp = j;
		while (mMap[i][--tmp] == C)
			total++;

		tmp = j;
		while (mMap[i][++tmp] == C)
			total++;

		mMax = std::max(mMax, total);

		total = 1, tmp;
		tmp = i;
		while (mMap[--tmp][j] == C)
			total++;
		tmp = i;
		while (mMap[++tmp][j] == C)
			total++;

		mMax = std::max(mMax, total);
	}


private:
	int mN, mMax = 0;
	vvc mMap;

};

void Solve()
{
	Candy candy;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}