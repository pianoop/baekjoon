//카잉 달력
//-------------------------------------------------------------------
#include <iostream>

int lcm(int a, int b)
{
	int r = 1;
	while (r != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		int N, M, x, y;
		std::cin >> M >> N >> x >> y;
		int n = N * M / lcm(N, M);
		if (N == y)
			y = 0;

		bool flag = 0;
		int i = x;
		for (; i <= n;i += M)
		{
			if (i % N == y)
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			std::cout << i << "\n";
		}
		else
			std::cout << "-1\n";
	}

	return 0;
}