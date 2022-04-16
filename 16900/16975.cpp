//수열과 쿼리 21
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vl;

class Fenwick
{
public:
	Fenwick(int n) :mN(n)
	{
		input();
	}

	void Query()
	{
		int m, q, i, j, k;
		std::cin >> m;
		while (m--)
		{
			std::cin >> q;
			if (q == 1)
			{
				std::cin >> i >> j >> k;
				update(i, k);
				update(j + 1, -k);
			}
			else
			{
				std::cin >> i;
				std::cout << sum(i) << "\n";
			}
		}
	}

private:
	void input()
	{
		mFenwick.resize(mN + 2);
		int now, pre = 0;

		for (int i = 1; i <= mN; i++)
		{
			std::cin >> now;
			update(i, now + pre);


			pre = -now;
		}
	}

	inline void update(int idx, int val)
	{
		for (int i = idx; i <= mN; i += (i & -i))
			mFenwick[i] += val;
	}

	inline ll sum(int i)
	{
		ll ans = 0;
		for (; i > 0; i -= (i & -i))
			ans += mFenwick[i];

		return ans;
	}

private:
	vl mFenwick;
	int mN;
};

void Solve()
{
	int N;
	std::cin >> N;
	Fenwick fen(N);
	fen.Query();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}