//집으로
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <cmath>
typedef long double ld;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	ld total = 0;
	int X, Y, D, T;
	std::cin >> X >> Y >> D >> T;

	std::cout << std::fixed;
	std::cout.precision(15);

	ld distance = sqrt(pow(X, 2) + pow(Y, 2));

	if (D <= T)
		std::cout << distance;
	else if (distance < D)
	{
		total += std::min(distance, std::min(D - distance + T, ld(2 * T)));

		std::cout << total;
	}
	else
	{
		int jumpcnt = distance / D;
		total += jumpcnt * T;
		distance -= jumpcnt * D;

		total += std::min(distance, ld(T));

		std::cout << total;
	}
	
	return 0;
}