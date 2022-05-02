//날짜 계산
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

void Solve()
{
	int e, s, m;
	std::cin >> e >> s >> m;
	if (s == 28)
		s = 0;
	if (m == 19)
		m = 0;

	while (true)
	{
		if (e % 28 == s && e % 19 == m)
		{
			std::cout << e;
			break;
		}
		else
			e += 15;
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}