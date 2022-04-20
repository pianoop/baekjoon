//요세푸스 문제 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> vi;

class Fenwick
{
public:
	Fenwick(int n, int k)
	{
		solve(n, k);
	}

private:
	void solve(int n, int k)
	{
		mi = 1 << int(floor(log2(n)));
		mN = (mi << 1) + 1;

		mFenwick.resize(mN , 1);
		for (int i = 1; i < mN; ++i)
		{
			if (i + (i & -i) < mN)
				mFenwick[i + (i & -i)] += mFenwick[i];
		}

		int order = k, tmp;
		std::cout << "<" << order;
		update(order);

		while (--n)
		{
			tmp = (order + k - 1) % n;
			if (tmp != 0)
				order = tmp;
			else
				order = n;

			search(order);
		}

		std::cout << ">";
	}

	inline void search(int k)
	{
		int total = 0, i = mi;

		while (true)
		{
			while (mFenwick[total | i] >= k && i > 0)
				i >>= 1;

			if (i == 0)
				break;

			total |= i;
			k -= mFenwick[total];
			i >>= 1;
		}

		if (k != 0)
			total++;

		std::cout <<", " << total;
		update(total);
	}

	inline void update(int idx)
	{
		for (int i = idx; i < mN; i += (i & -i))
			mFenwick[i]--;
	}

	inline int sum(int i)
	{
		int ans = 0;
		for (; i > 0; i -= (i & -i))
			ans += mFenwick[i];

		return ans;
	}

private:
	vi mFenwick;
	int mN, mi;

};

void Solve()
{
	int N, K;
	std::cin >> N >> K;
	Fenwick fen(N, K);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}