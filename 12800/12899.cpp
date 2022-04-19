//데이터 구조
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Fenwick
{
public:
	Fenwick()
	{
		solve();
	}

private:
	void solve()
	{
		mFenwick.resize(mN);

		char q;
		int Q, x;
		std::cin >> Q;
		while (Q--)
		{
			std::cin >> q >> x;

			if (q == '1')
				updateP(x);
			else
				search(x);
		}

	}

	inline void search(int k)
	{
		int total = 0, i = 1048576; // 1 << 20s

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

		std::cout << total << "\n";
		updateM(total);
	}

	inline void updateP(int idx)
	{
		for (int i = idx; i < mN; i += (i & -i))
			mFenwick[i]++;
	}

	inline void updateM(int idx)
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
	int mN = 2097153; //1 << 21 + 1

};

void Solve()
{
	Fenwick fen;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}