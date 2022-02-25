//PIZZA ALVOLOC
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int x1, x2, y1, y2, x3, x4, y3, y4;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	int b = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);

	if (a < 0)
		a = -1;
	else if (a > 0)
		a = 1;

	if (b < 0)
		b = -1;
	else if (b > 0)
		b = 1;

	if (a * b < 0)
		std::cout << 1;
	else
		std::cout << 0;

	return 0;
}