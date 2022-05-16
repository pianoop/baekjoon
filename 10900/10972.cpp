//다음 순열
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

void Solve()
{
	int n;
	std::cin >> n;

	vi arr(n);
	for (auto& i : arr)
		std::cin >> i;

	if (std::next_permutation(arr.begin(), arr.end()))
	{
		for (auto i : arr)
			std::cout << i << " ";
	}
	else
		std::cout << "-1";
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}