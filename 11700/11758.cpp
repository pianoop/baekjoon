//CCW
//-------------------------------------------------------------------
#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int a, b, c, d, e, f;
	std::cin >> a >> b >> c >> d >> e >> f;

	int answer = (c - a) * (f - b) - (d - b) * (e - a);
	if (answer > 0)
		std::cout << 1;
	else if (answer < 0)
		std::cout << -1;
	else
		std::cout << 0;

	return 0;
}