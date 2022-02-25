//주유소
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

int main()
{
	int N;
	std::vector<long long> vdist;

	scanf("%d", &N);
	for (int x, i = 0;i < N - 1;i++)
	{
		scanf("%d", &x);
		vdist.push_back(x);
	}

	int oilprice;
	long long money = 0;
	scanf("%d", &oilprice);
	for (int x, i = 0;i < N - 1;i++)
	{
		money += oilprice * vdist[i];
		scanf("%d", &x);
		if (oilprice > x)
			oilprice = x;
	}

	printf("%lld", money);

	return 0;
}