//선 긋기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MIN     (-2147483647 - 1)
typedef std::vector<std::pair<int, int> > vpi;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vpi vpi1(N);
	for (int i = 0;i < N;i++)
	{
		std::cin >> vpi1[i].first >> vpi1[i].second;
	}

	std::sort(vpi1.begin(), vpi1.end());

	int ans = 0, left = INT_MIN, right = INT_MIN;
	for (int i = 0;i < N;i++)
	{
		if (right < vpi1[i].first)
		{
			ans += right - left;
			left = vpi1[i].first;
			right = vpi1[i].second;
		}
		else if (right < vpi1[i].second)
			right = vpi1[i].second;
	}
	ans += right - left;
	std::cout << ans;

	return 0;
}
