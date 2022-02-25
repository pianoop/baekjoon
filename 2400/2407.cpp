//조합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;
typedef long long ll;
#define e18 1000000000000000000

class DoubleLong
{
public:
	ll mA;
	ll mB;

	DoubleLong() :mA(0), mB(1) {}
	DoubleLong(ll a, ll b) :mA(a), mB(b) {}

	DoubleLong operator +(DoubleLong other)
	{
		ll a = this->mA + other.mA;
		ll b = this->mB + other.mB;
		if (b >= e18)
		{
			b -= e18;
			a++;
		}
		return DoubleLong(a, b);
	}

	void mPrint()
	{
		if (mA == 0)
		{
			std::cout << mB;
		}
		else
		{
			std::cout << mA;
			int size = 18;
			ll temp = mB;
			while (temp != 0)
			{
				size--;
				temp /= 10;
			}
			while (size--)
			{
				std::cout << "0";
			}
			std::cout << mB;
		}
	}
};
typedef std::vector<DoubleLong> vD;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	if (m > n / 2)
		m = n - m;

	std::vector<vD> Comb(n + 1, vD(m + 1));
	for (int i = 2;i < n;i++)
	{
		for (int j = 1;j < i  && j < m+1;j++)
		{
			Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];
		}
	}
	Comb[n][m] = Comb[n - 1][m - 1] + Comb[n - 1][m];
	Comb[n][m].mPrint();

	return 0;
}