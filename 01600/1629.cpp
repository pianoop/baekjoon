//곱셈
//-------------------------------------------------------------------
#include <iostream>
typedef long long ll;

ll PRIME;

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
	ll A, B, answer;
	scanf("%lld %lld %lld", &A, &B, &PRIME);
	answer = pow1(A, B);

	printf("%lld", answer);

	return 0;
}