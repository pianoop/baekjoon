//이항 계수 4
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;

ll m;

int pow1(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ret;
}

int main(){
    ll n, r;
	std::cin >> n >> r >> m;
	ll ans = 1;
	
	std::vector<int> fac;
	fac.push_back(1);
	for (int i = 1;i < int(m);i++)
		fac.push_back((fac.back() * i )% m);

	
	while ( n || r ){
		ll N = n % m;
		ll R = r % m;
		if ( N < R ){
			ans = 0;
			break;
		}
		ans *= fac[N] * pow1(fac[R] * fac[N-R] % m, m-2);
		ans %= m;
		n /= m;
		r /= m;
	}
	printf("%lld",ans);
	
    return 0;
}