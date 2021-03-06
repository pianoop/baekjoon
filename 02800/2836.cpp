//수상 택시
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX		2147483647
typedef std::vector<std::pair<int, int> > vpi;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	long long M;
	std::cin >> N >> M;

	vpi vpi1;
	vpi1.reserve(N);
	for (int x, y, i = 0;i < N;i++)
	{
		std::cin >> x >> y;
		if (x > y)
		{
			vpi1.emplace_back(x , y);
		}
	}

	int ans = 0;
	if (!vpi1.empty())
	{
		std::sort(vpi1.begin(), vpi1.end(), std::greater<>());

		int left = INT_MAX, right = INT_MAX;
		int a, b;
		for (auto &[a,b] : vpi1)
		{
			if (left > a)
			{
				ans += right - left;
				left = b;
				right = a;
			}
			else if (left > b)
				left = b;
		}
		ans += right - left;
	}
	std::cout << ans * 2+ M;

	return 0;
}