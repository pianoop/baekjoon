//팩토리얼 0의 개수
//-------------------------------------------------------------------
#include <iostream>

int main()
{
	int N;
	scanf("%d", &N);

	int five = 0;
	for (int i = 5;i <= N;i*=5)
	{
		five += N / i;
	}
	printf("%d",five);
	
	return 0;
}