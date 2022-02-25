//이항 계수 1
//-------------------------------------------------------------------
#include <iostream>

int fac(int n, int i = 1)
{
	int total = 1;
	for (;i <= n;i++)
		total *= i;
	return total;
}
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", fac(N, N - K + 1) / fac(K));
}