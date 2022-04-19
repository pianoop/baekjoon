//사탕상자
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
		int Q, a, b;
		std::cin >> Q;
		while (Q--)
		{
			std::cin >> q >> a;

			if (q == '1')
				search(a);
			else
			{
				std::cin >> b;
				update(a, b);
			}
		}

	}

	inline void search(int k)
	{
		int total = 0, i = 524288; // 1 << 19

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
		update(total, -1);
	}

	inline void update(int idx, int val)
	{
		for (int i = idx; i < mN; i += (i & -i))
			mFenwick[i]+= val;
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
	int mN = 1048577; //1 << 20 + 1

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