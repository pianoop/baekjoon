//행렬 제곱
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<std::vector<int> > vvint;

int n, PRIME = 1000;

vvint operator*(const vvint& A, const vvint& B)
{
	vvint C(n, std::vector<int>(n, 0));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < n;k++)
			{
				C[i][j] += (A[i][k] * B[k][j]);
			}
			C[i][j] %= PRIME;
		}
	}
	return C;
}

vvint PowMatrix(vvint A, long long b)
{
	vvint ret(n,std::vector<int>(n,0));
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
	vvint vva, vvanswer;
	long long B;
	scanf("%d %lld", &n, &B);
	vva.resize(n, std::vector<int>(n, 0));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			scanf("%d", &vva[i][j]);
		}
	}

	vvanswer = PowMatrix(vva, B);

	for (auto ans : vvanswer)
	{
		for (auto answer : ans)
		{
			printf("%d ", answer);
		}
		printf("\n");
	}

	return 0;
}