//알고리즘 수업 - 피보나치 수 1
//-------------------------------------------------------------------
#include <iostream>


void Solve()
{
	int n;
	std::cin >> n;

	int p[41];
	p[1] = p[2] = 1;
	for (int i = 3; i <= n; i++)
		p[i] = p[i - 1] + p[i - 2];

	std::cout << p[n] << " " << n - 2;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}