//돌무더기 게임 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

void Solve()
{
	vi arr(3);
	for (auto& a : arr)
		std::cin >> a;
	std::sort(arr.begin(), arr.end());
	if (arr[0] % 2 == 0)
	{
		if (arr[1] % 2 == 0 || arr[2] % 2 == 0)
			printf("R");
		else
			printf("B");
	}
	else
	{
		if (arr[1] % 2 == 1 || arr[2] % 2 == 1)
			printf("B");
		else
			printf("R");
	}
	printf("\n");
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while(T--)
		Solve();

	return 0;
}