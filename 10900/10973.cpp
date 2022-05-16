//이전 순열
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> vi;

bool Prev_permutation(std::vector<int>& a, int n) 
{
	int i = --n;
	while (i > 0 && !(a[i - 1] > a[i]))
		i--;
	if (i <= 0)
		return false;

	i--;
	int j = n;
	while (a[j] >= a[i])
		j--;

	std::swap(a[i], a[j]);
	i++;

	while (i < n)
	{
		std::swap(a[i], a[n]);
		i++, n--;
	}
	/*std::reverse(a.begin() + i + 1, a.end());*/
	return true;
}

void Solve()
{
	int n;
	std::cin >> n;

	vi arr(n);
	for (auto& i : arr)
		std::cin >> i;

	if (Prev_permutation(arr, (int)arr.size()))
	{
		for (auto i : arr)
			std::cout << i << " ";
	}
	else
		std::cout << -1;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}