//약수
//-------------------------------------------------------------------
#include <iostream>
#define INT_MAX 2147483647

int main()
{
	int N;
	scanf("%d", &N);
	int Max = 0, Min = INT_MAX;
	
	int x;
	while (N--)
	{
		scanf("%d", &x);
		if (Max < x)
			Max = x;
		if (Min > x)
			Min = x;
	}

	printf("%d", Min * Max);

	return 0;
}