//선분 교차 1
//-------------------------------------------------------------------
#include <iostream>
typedef long long ll;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	ll x1, x2, y1, y2, x3, x4, y3, y4;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	ll a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	ll b = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);

	if (a < 0)
		a = -1;
	else if (a > 0)
		a = 1;

	if (b < 0)
		b = -1;
	else if (b > 0)
		b = 1;

	ll c = (x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3);
	ll d = (x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3);

	if (c < 0)
		c = -1;
	else if (c > 0)
		c = 1;

	if (d < 0)
		d = -1;
	else if (d > 0)
		d = 1;

	if (a * b < 0 && c * d < 0)
		std::cout << 1;
	else
		std::cout << 0;

	return 0;
}