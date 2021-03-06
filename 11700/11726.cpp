//2xn 타일링
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int PRIME = 10007;
int n = 2;

vvi operator*(const vvi& A, const vvi& B)
{
	vvi C(n, vi(n, 0));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < n;k++)
			{
				C[i][j] += (A[i][k] * B[k][j]) % PRIME;
				C[i][j] %= PRIME;
			}
		}
	}
	return C;
}

vvi PowMatrix(vvi A, int b)
{
	vvi ret(n, vi(n, 0));
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
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	vvi vva, vvanswer;
	int B;
	std::cin >> B;
	B++;
	vva.resize(n, vi(n, 1));
	vva[1][1] = 0;

	if (B < 3)
	{
		std::cout<<"1";
	}
	else
	{
		vvanswer = PowMatrix(vva, B - 2);
		std::cout<<(vvanswer[0][0] + vvanswer[0][1]) % PRIME;
	}

	return 0;
}