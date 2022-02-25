//Z
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int pow1(int a, int b)
{
	int ans = 1;
	for (int i = 0;i < b;i++)
		ans *= a;
	return ans;
}

void Z(int n, int m, int L, int& step)
{
	if (L == 1)
	{
		return;
	}
	L /= 2;
	int LL = L * L;
	int a = n-L, b = m-L;
	if (a >= 0 && b >= 0)
	{
		n = a, m = b;
		step += LL * 3;
	}
	else if (a >= 0)
	{
		n = a;
		step += LL * 2;
	}
	else if (b >= 0)
	{
		m = b;
		step += LL;
	}
	Z(n, m, L, step);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, r, c;
	std::cin >> N >> r >> c;

	int L = pow1(2, N);
	int step = 0;
	Z(r, c, L, step);

	std::cout << step;

	return 0;
}