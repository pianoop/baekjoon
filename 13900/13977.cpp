//이항 계수와 쿼리 
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int DIV = 1'000'000'007;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int N, K;
		cin >> N >> K;

		cout << mFac[N] * (pow1((ll)mFac[K] * mFac[N - K] % DIV, DIV - 2)) % DIV << "\n";
	}


private:
	void input()
	{
		mFac.resize(4'000'001);
		mFac[0] = 1;
		for (int i = 1; i < 4'000'001; i++)
			mFac[i] = (ll)mFac[i - 1] * i % DIV;
	}

	ll pow1(ll a, int b)
	{
		ll ret = 1;
		while (b)
		{
			if (b & 1)
				ret = (ret * a) % DIV;
			a = (a * a) % DIV;
			b >>= 1;
		}
		return ret;
	}

private:
	vi mFac;
	
};


void Solve()
{
	Q q;

	int T;
	cin >> T;
	while (T--)
		q.Solve();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}