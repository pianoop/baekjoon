//본대 산책2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> vll;
#define DIVIDE 1'000'000'007

vll operator*(const vll& A, const vll& B)
{
	vll ret(A.size(), vl(B[0].size()));

	for (int i = 0; i < int(A.size()); i++)
	{
		for (int k = 0; k < int(B.size()); k++)
		{
			for (int j = 0; j < int(B[0].size()); j++)
			{
				ret[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (auto& n : ret)
		for (auto& nm : n)
			nm %= DIVIDE;

	return ret;
}

class Graph
{
public:
	Graph() {}

	void PrintAns(int n)
	{
		ll ans = fastPowAns(n);

		printf("%lld", ans);
	}

private:
	ll fastPowAns(int b)
	{
		vll A, ret(mN, vl(mN));
		A = mGraph;
		for (int i = 0; i < mN; i++)
			ret[i][i] = 1;

		while (b != 0)
		{
			if (b & 1)
			{
				ret = ret * A;
			}
			A = A * A;
			b >>= 1;
		}

		return ret[mN-1][mN-1];
	}



private:
	vll mGraph = { {0,1,1,0,0,0,0,0}, {1,0,0,1,0,0,0,0}, {1,0,0,1,1,0,0,0}, {0,1,1,0,1,1,0,0}
			,{0,0,1,1,0,1,1,0}, {0,0,0,1,1,0,1,1}, {0,0,0,0,1,1,0,1}, {0,0,0,0,0,1,1,0} };
	int mN = 8;

};

void Solve()
{
	int n;
	std::cin >> n;

	Graph graph;
	graph.PrintAns(n);
}

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);

	Solve();

	return 0;
}