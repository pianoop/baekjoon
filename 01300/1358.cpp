//하키
//-------------------------------------------------------------------
#include <iostream>

void Solve()
{
	int w, h, mx, my, n;
	std::cin >> w >> h >> mx >> my >> n;

	int r = h / 2, ex = mx + w, Cy = my + r, ey = my + h, ans = 0;
	int x, y, dx, dy, llx = mx - r, rrx = ex + r;
	r *= r;
	while (n--)
	{
		std::cin >> x >> y;
		if (my <= y && ey >= y)
		{
			if (mx <= x && ex >= x)
				ans++;
			else if (llx <= x && mx >= x)
			{
				dx = std::abs(x - mx), dy = std::abs(y - Cy);
				if (r >= dx * dx + dy * dy)
					ans++;
			}
			else if (ex <= x && rrx >= x)
			{
				dx = std::abs(x - ex), dy = std::abs(y - Cy);
				if (r >= dx * dx + dy * dy)
					ans++;
			}
		}
	}

	std::cout << ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}