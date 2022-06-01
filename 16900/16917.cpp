//양념 반 후라이드 반
//-------------------------------------------------------------------
#include <iostream>


void Solve()
{
	int a, b, c, x, y, total = 0;
	std::cin >> a >> b >> c >> x >> y;

	int ab = a + b;
	c *= 2;
	if (c < ab)
	{
		if (x < y)
		{
			total += x * c;
			y -= x;
			x = 0;
		}
		else
		{
			total += y * c;
			x -= y;
			y = 0;
		}
	}

	if (x > 0)
	{
		if (a < c)
			total += x * a;
		else
			total += x * c;
	}

	if (y > 0)
	{
		if (b < c)
			total += y * b;
		else
			total += y * c;
	}
	
	std::cout << total;

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}