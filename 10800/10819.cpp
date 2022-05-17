//차이를 최대로
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> vi;

void Solve()
{
	int n;
	std::cin >> n;

	vi arr(n);
	for (auto& i : arr)
		std::cin >> i;
	std::sort(arr.begin(), arr.end());

	int max = 0, tot;
	do
	{
		tot = 0;
		for (int i = 1; i < n; i++)
		{
			tot += std::abs(arr[i] - arr[i - 1]);
		}

		max = std::max(max, tot);
	} while (std::next_permutation(arr.begin(), arr.end()));

	std::cout << max;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}