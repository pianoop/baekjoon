//약수의 합 2
//-------------------------------------------------------------------
#include <iostream>
typedef long long ll;

void Solve()
{
	int n;
	std::cin >> n;
	ll ans = 0;
	int i = 1;
	for (; i <= n / 2; i++)
		ans += i * (n / i);
	for (; i <= n; i++)
		ans += i;

	std::cout << ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}