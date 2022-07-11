//N포커
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

const int DIV = 10'007;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int ans = 0, end = mN / 4;
		for (int i = 1, i4 = 4; i <= end; i++, i4 += 4)
		{
			int tmp = comb(13, i) * comb(52 - i4, mN - i4);

			if (i & 1)
				ans += tmp;
			else
				ans -= tmp;
		}


		ans %= DIV;
		if (ans < 0)
			ans = (ans + DIV) % DIV;

		cout << ans;
	}


private:
	void input()
	{
		cin >> mN;
	}

	int comb(int N, int K)
	{
		if (K > (N >> 1))
			K = N - K;

		return fac(N, N - K + 1) * (pow1(fac(K), DIV - 2)) % DIV;
	}

	int pow1(int a, int b)
	{
		int ret = 1;

		while (b)
		{
			if (b & 1)
				ret = (ret * a) % DIV;
			a = (a * a) % DIV;
			b >>= 1;
		}

		return ret;
	}

	int fac(int n, int i = 1)
	{
		int total = 1;

		for (; i <= n; i++)
			total = (total * i) % DIV;

		return total;
	}


private:
	int mN;

};


void Solve()
{
	Q q;
	q.Solve();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}