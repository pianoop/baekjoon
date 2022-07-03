//GCD(n, k) = 1
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;


class Q
{
public:
	Q()
	{
		input();
		getPrime();
	}

	void Solve()
	{
		int exp;
		ll n = mN, ans = 1;
		for (auto p : mPrime)
		{
			if (n % p == 0)
			{
				exp = getExp(n, p);
				ll tmp = _pow(p, exp);
				ans *= (tmp - tmp / p);
			}

			if (n == 1)
				break;
		}

		if (n != 1)
			ans *= (n - 1);

		cout << ans;
	}


private:
	void input()
	{
		cin >> mN;
		mM = int(sqrt(mN));
	}


	void getPrime()
	{
		bool* prime = new bool[mM + 1];
		memset(prime, false, sizeof(bool) * (mM + 1));
		for (int i = 2; i <= mM; i++)
		{
			if (!prime[i])
			{
				mPrime.push_back(i);
				for (int j = i; j <= mM; j += i)
					prime[j] = true;
			}
		}

		delete[] prime;
	}

	int getExp(ll& n, int P)
	{
		int ret = 0;
		while (n % P == 0)
		{
			n /= P;
			ret++;
		}

		return ret;
	}

	ll _pow(ll a, int b)
	{
		ll ret = 1;
		while (b)
		{
			if (b & 1)
				ret = ret * a;
			a = a * a;
			b >>= 1;
		}

		return ret;
	}


private:
	vi mPrime;
	ll mN, mM;

};


void Solve()
{
	Q q;
	q.Solve();
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}