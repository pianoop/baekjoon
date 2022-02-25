//최소공배수
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
	int N, lcm;
	scanf("%d", &N);
	
	for (int a,b,i = 0;i < N;i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", a*b/GCD(a,b));
	}

	return 0;
}