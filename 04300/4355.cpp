//서로소
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> vi;


class Q
{
public:
	Q()
	{
		input();
		getPrime();
	}

	void Solve(int n)
	{
		int exp;
		int ans = 1;
		for (auto p : mPrime)
		{
			if (n % p == 0)
			{
				exp = getExp(n, p);
				int tmp = _pow(p, exp);
				ans *= (tmp - tmp / p);
			}

			if (n == 1)
				break;
		}

		if (n != 1)
			ans *= (n - 1);

		cout << ans << "\n";
	}


private:
	void input()
	{

	}


	void getPrime()
	{
		int n = 31623; // sqrt(1e9) + 1
		bool* prime = new bool[n];
		memset(prime, false, sizeof(bool) * n);
		for (int i = 2; i < n; i++)
		{
			if (!prime[i])
			{
				mPrime.push_back(i);
				for (int j = i; j < n; j += i)
					prime[j] = true;
			}
		}

		delete[] prime;
	}

	int getExp(int& n, int P)
	{
		int ret = 0;
		while (n % P == 0)
		{
			n /= P;
			ret++;
		}

		return ret;
	}

	int _pow(int a, int b)
	{
		int ret = 1;
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

};


void Solve()
{
	Q q;

	int N;
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;

		q.Solve(N);
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}