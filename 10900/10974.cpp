//모든 순열
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> vi;

bool Next_permutation(std::vector<int>& a, int n) 
{
	int i = n;
	while (i > 0 && !(a[i - 1] < a[i]))
		i--;
	if (i <= 0)
		return false;

	int& ai = a[--i];
	int j = n;
	while (a[j] <= ai)
		j--;

	std::swap(ai, a[j]);
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
	int tmp = 1;
	for (auto& i : arr)
		i = tmp++;

	n--;
	do
	{
		for (auto i : arr)
			std::cout << i << " ";
		std::cout << "\n";
	} while (Next_permutation(arr, n));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}