//다리 놓기
//-------------------------------------------------------------------
#include <iostream>
typedef unsigned long long ull;

ull fac(const int& a, const int b=1)
{
	ull ans = 1;
	for (int i = b;i <= a;i++)
		ans *= i;
	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);

	int x, y;
	while (N--&&scanf("%d %d",&x,&y))
	{
		if (x > y / 2)
			x = y - x;
		if (x == 0)
			printf("1\n");
		else
			printf("%llu\n", fac(y, y - x + 1) / fac(x));
	}

	return 0;
}