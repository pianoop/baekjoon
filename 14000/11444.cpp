//피보나치 수 6
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;


ll PRIME = 1000000007;
int n = 2;

vvll operator*(const vvll& A, const vvll& B)
{
	vvll C(n, vll(n, 0));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < n;k++)
			{
				C[i][j] += (A[i][k] * B[k][j])%PRIME;
				C[i][j] %= PRIME;
			}
		}
	}
	return C;
}

vvll PowMatrix(vvll A, ll b)
{
	vvll ret(n,vll(n,0));
	for (int i = 0;i < n;i++)
		ret[i][i] = 1;

	while (b)
	{
		if (b & 1)
		{
			ret = (ret * A);
		}
		A = (A * A);
		b >>= 1;
	}
	return ret;
}

int main()
{
	vvll vva, vvanswer;
	ll B;
	scanf("%lld", &B);
	vva.resize(n, vll(n, 1));
	vva[1][1] = 0;

	if (B < 3)
	{
		printf("1");
	}
	else
	{
		vvanswer = PowMatrix(vva, B - 2);
		printf("%lld", (vvanswer[0][0] + vvanswer[0][1]) % PRIME);
	}

	return 0;
}