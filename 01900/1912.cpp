//연속합
//-------------------------------------------------------------------
#include <iostream>

int main()
{
	int N;
	scanf("%d", &N);
	
	int x, total=0, Max=-1001;
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &x);
		if (total + x > Max)
			Max = total+x;
		total += x;
		if (total < 0)
			total = 0;
	}
	printf("%d", Max);

	return 0;
}