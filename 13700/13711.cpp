//LCS 4
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> v1(N+1,0), LIS;

	int x;
	for (int i = 1;i <= N;i++)
	{
		scanf("%d", &x);
		v1[x] = i;
	}
	LIS.push_back(-1);
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &x);
		if (LIS.back() < v1[x])
			LIS.push_back(v1[x]);
		else
			*(std::lower_bound(LIS.begin(), LIS.end(), v1[x])) = v1[x];
	}

	printf("%d", (int)LIS.size() - 1);

	return 0;
}