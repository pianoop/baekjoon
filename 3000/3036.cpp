//링
//-------------------------------------------------------------------
#include <iostream>

int GCD(const int& fA, const int& fB)
{
	int r = fA % fB;
	if (r == 0)
		return fB;
	return GCD(fB, r);
}

int main()
{
	int N, first;
	scanf("%d%d", &N,&first);

	int gcd;
	for (int b, i = 1;i < N;i++)
	{
		scanf("%d", &b);
		gcd = GCD(first, b);
		printf("%d/%d\n", first / gcd, b / gcd);
	}

	return 0;
}