//타일 채우기 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector <vl> vvl;


const int DIV = 1'000'000'007;

vvl operator*(vvl& a, vvl& b) // 2 X 2 Matrix
{
	vvl ret(2, vl(2));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ll& now = ret[i][j];
			for (int k = 0; k < 2; k++)
				now += a[i][k] * b[k][j];

			now %= DIV;
			if (now < 0)
				now += DIV;
		}
	}

	return ret;
}

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		if (mbEven)
		{
			if (mN == 1)
			{
				std::cout << 3;
				return;
			}

			vvl Matrix(2, vl(2));
			Matrix[0][0] = 4, Matrix[0][1] = -1, Matrix[1][0] = 1;


			Matrix = matPow(Matrix, mN - 1);

			ll ans = (Matrix[0][0] * 3 + Matrix[0][1]) % DIV;
			if (ans < 0)
				ans += DIV;

			std::cout << ans;
		}
		else
			std::cout << 0;
	}


private:
	void input()
	{
		std::cin >> mN;
		if (!(mN & 1))
			mbEven = true;

		mN >>= 1;
	}

	vvl matPow(vvl A, ll b)
	{
		vvl ret(2, vl(2));
		ret[0][0] = ret[1][1] = 1;

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


private:
	ll mN;
	bool mbEven = false;
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