//조합 0의 개수
//-------------------------------------------------------------------
#include <iostream>
typedef long long ll;

ll Min(const ll& a, const ll& b)
{
	return a < b ? a : b;
}

ll findxcount(const ll& a, const int& b)
{
	ll count = 0;
	for (ll i = b;i <= a;i *= b)
		count += a / i;
	return count;
}

int main()
{
	ll N, R;
	scanf("%lld %lld", &N, &R);

	ll two,five;
	two = findxcount(N, 2) - findxcount(R, 2) - findxcount(N - R, 2);
	five = findxcount(N, 5) - findxcount(R, 5) - findxcount(N - R, 5);

	printf("%lld", Min(two, five));

	return 0;
}