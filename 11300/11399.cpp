//ATM
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> vpay;

	for (int x, i = 0;i < N;i++)
	{
		scanf("%d", &x);
		vpay.push_back(x);
	}
	std::sort(vpay.begin(), vpay.end());

	int totaltime = 0;
	for (int i = 0;i < N;i++)
		totaltime += vpay[i]*(N-i);

	printf("%d", totaltime);

	return 0;
}