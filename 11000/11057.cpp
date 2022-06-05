//오르막 수
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;


void Solve()
{
	const int DIV = 10'007;

	int n;
	std::cin >> n;

	int *prev = new int[10], *next = new int[10];
	for (int i = 0; i < 10; i++)
		prev[i] = 1;

	while(--n)
	{
		for (int i = 0; i < 10; i++)
		{
			next[i] = prev[i];
			for (int j = i + 1; j < 10; j++)
				next[i] += prev[j];

			next[i] = next[i] % DIV;
		}

		std::swap(next, prev);
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += prev[i];

	std::cout << ans%DIV;

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}