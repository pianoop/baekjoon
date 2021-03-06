//선분 교차 3
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef long double ld;

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

	if (a * b == 0 && c * d == 0)
	{
		std::pair<ll, ll> dot1 = { x1,y1 }, dot2 = { x2,y2 }, dot3 = { x3,y3 }, dot4 = { x4,y4 };
		if ((x2 - x1) * (y4 - y3) != (x4 - x3) * (y2 - y1))
		{
			std::cout << 1 << "\n";
			if (dot1 == dot3 || dot1 == dot4)
				std::cout << dot1.first << " " << dot1.second;
			else
				std::cout << dot2.first << " " << dot2.second;
		}
		else
		{
			if (dot1 > dot2)
				std::swap(dot1, dot2);
			if (dot3 > dot4)
				std::swap(dot3, dot4);
			if (dot3 < dot2 && dot1 < dot4)
			{
				std::cout << 1 << "\n";
			}
			else if (dot3 == dot2 && dot1 < dot4)
			{
				std::cout << 1 << "\n" << dot3.first << " " << dot3.second;
			}
			else if (dot3 < dot2 && dot1 == dot4)
			{
				std::cout << 1 << "\n" << dot1.first << " " << dot1.second;
			}
			else if (dot3 == dot2 && dot1 == dot4)
			{
				std::cout << 1 << "\n" << dot1.first << " " << dot1.second;
			}
			else
				std::cout << 0;
		}
	}
	else if (a * b <= 0 && c * d <= 0)
	{
		ld c1, c2, c3, c4, c5, c6, xans, yans;

		c1 = ld(y2 - y1), c2 = ld(x1 - x2), c3 = ld(y4 - y3), c4 = ld(x3 - x4);
		c5 = ld(c1 * x1 + c2 * y1), c6 = ld(c3 * x3 + c4 * y3);

		ld temp = c1 * c4 - c2 * c3;
		xans = (c5 * c4 - c2 * c6) / temp;
		yans = (c1 * c6 - c5 * c3) / temp;

		std::cout << 1 << "\n";

		std::cout.fixed;
		std::cout.precision(17);
		std::cout << xans << " " << yans;
	}
	else
		std::cout << 0;

	return 0;
}