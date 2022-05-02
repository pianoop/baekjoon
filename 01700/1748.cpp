//수 이어 쓰기 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

void Solve()
{
	int n, coef = 9, cnt = 1;
	std::cin >> n;
	
	long long ans = 0;
	while (true)
	{
		if (n > coef)
		{
			ans += coef * cnt;
			n -= coef;
			coef *= 10;
			cnt++;
		}
		else
		{
			ans += n * cnt;
			break;
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