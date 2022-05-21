//어린 왕자
//-------------------------------------------------------------------
#include <iostream>

void Solve()
{
	int Sx, Sy, Dx, Dy, n;
	std::cin >> Sx >> Sy >> Dx >> Dy >> n;

	int x, y, r, ans = 0, dx, dy;
	while (n--)
	{
		std::cin >> x >> y >> r;
		
		dx = std::abs(x - Sx), dy = std::abs(y - Sy);
		r *= r;
		if (dx * dx + dy * dy < r)
		{
			dx = std::abs(x - Dx), dy = std::abs(y - Dy);
			if (dx * dx + dy * dy > r)
				ans++;
		}
		else
		{
			dx = std::abs(x - Dx), dy = std::abs(y - Dy);
			if (dx * dx + dy * dy < r)
				ans++;
		}
	}

	std::cout << ans<<"\n";
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while(T--)
		Solve();

	return 0;
}