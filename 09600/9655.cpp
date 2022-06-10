//돌 게임
//-------------------------------------------------------------------
#include <iostream>


void Solve()
{
	int n;
	std::cin >> n;

	if (n & 1)
		std::cout << "SK";
	else
		std::cout << "CY";
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}