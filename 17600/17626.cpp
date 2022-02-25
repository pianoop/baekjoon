//Four Squares
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> vi;

int Min = 4;

int Sqr(int& a)
{
	return int(floor(sqrt(long(a)) + 0.00001));;
}

void BF(int x, int n, const vi& sqrts)
{
	if (n >= Min)
		return;
	int i = Sqr(x);
	for (int a ;i > 0;i--)
	{
		a = x - sqrts[i];
		if (a == 0 && n < Min)
		{
			Min = n;
			return;
		}
		else
		{
			BF(a, n + 1, sqrts);
			if (n >= Min)
				return;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int sq = Sqr(N);

	vi sqrts(sq + 1);
	for (int i = 1;i <= sq;i++)
	{
		sqrts[i] = i * i;
	}

	BF(N, 1, sqrts);

	std::cout << Min;

	return 0;
}