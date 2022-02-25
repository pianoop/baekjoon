//이항 계수 3
//-------------------------------------------------------------------
#include <iostream>
#define ull unsigned long long

const ull PRIME = 1000000007ULL;

ull pow1(ull a, int b)
{
	ull ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % PRIME;
		a = (a * a) % PRIME;
		b >>= 1;
	}
	return ret;
}

ull fac(int n, int i = 1)
{
	ull total = 1;
	for (;i <= n;i++)
		total = (total * i) % PRIME;
	return total;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
    if (K > N / 2)
		K = N - K;
	printf("%llu", (fac(N, N - K + 1)*(pow1(fac(K),PRIME-2))%PRIME));

	return 0;
}