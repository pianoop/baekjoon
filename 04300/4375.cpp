//1
//-------------------------------------------------------------------
#include <iostream>

void Solve()
{
	int n, ans, nlsb, multiple, mlsb, tmp;
	while (std::cin >> n)
	{
		ans = 0;
		multiple = n;
		nlsb = n % 10;

		while (true)
		{
			tmp = 0;
			mlsb = multiple % 10;
			while (mlsb != 1)
			{
				mlsb = (mlsb + nlsb) % 10;
				tmp++;
			}

			ans++;
			multiple += tmp * n;
			multiple /= 10;
			if (multiple == 0)
				break;
		}

		std::cout << ans << "\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}
