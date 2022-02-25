//두 원
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <cmath>
typedef long double ld;


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	ld x1, y1, r1, x2, y2, r2;
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	ld d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (r1 < r2)
	{
		std::swap(x1, x2);  std::swap(y1, y2);  std::swap(r1, r2);
	}

	std::cout << std::fixed;
	std::cout.precision(3);

	if (r1 + r2 <= d)
		std::cout << "0.000";
	else if (r2 + d <= r1)
		std::cout << r2 * r2 * acos(-1);
	else
	{
		ld theta1 = 2 * acos((pow(r1, 2) + pow(d, 2) - pow(r2, 2)) / (2 * r1 * d));
		ld theta2 = 2 * acos((pow(r2, 2) + pow(d, 2) - pow(r1, 2)) / (2 * r2 * d));

		ld ans = ((pow(r1, 2) * (theta1 - sin(theta1))) + (pow(r2, 2) * (theta2 - sin(theta2)))) / 2;
		std::cout << round(ans*pow(10,3))/pow(10,3);
	}

	return 0;
}