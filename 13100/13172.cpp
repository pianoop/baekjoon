//Σ
//-------------------------------------------------------------------
#include <iostream>
typedef long long ll;

ll PRIME = 1000000007;

ll pow1(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % PRIME;
		a = (a * a) % PRIME;
		b >>= 1;
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	ll ans = 0;
	while (N--)
	{
		int a;
		ll b;
		std::cin >> a >> b;

		ans = (ans + b * pow1(a, PRIME - 2)) % PRIME;
	}

	std::cout << ans;

	return 0;
}