//이항 계수 2
//-------------------------------------------------------------------
#include <iostream>

int pow(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % 10007;
		a = (a * a) % 10007;
		b >>= 1;
	}

	return ret;
}

int fac(int n, int i = 1)
{
	int total = 1;
	for (;i <= n;i++)
	{
		total *= i;
		total %= 10007;
	}
	return total;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", (fac(N, N - K + 1) * pow(fac(K) % 10007, 10005) % 10007));
	return 0;
}