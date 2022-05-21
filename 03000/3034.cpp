//앵그리 창영
//-------------------------------------------------------------------
#include <iostream>


void Solve()
{
	int n, a, b;
	std::cin >> n >> a >> b;
	a = a * a + b * b;
	while (n--)
	{
		std::cin >> b;
		if (b * b <= a)
			std::cout << "DA\n";
		else
			std::cout << "NE\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}