//LRH 식물
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef std::vector<int> vi;

class Fenwick
{
public:
	Fenwick()
	{
		input();
	}

private:
	void input()
	{
		mFenwick.resize(mN);
		int a, b, n, suma, sumb;
		std::cin >> n;

		while (n--)
		{
			std::cin >> a >> b;
			suma = sum(a);
			sumb = sum(b);
			std::cout << suma + sumb << "\n";
			
			if (suma != 0)
			{
				update(a, -suma);
				update(a + 1, 1 + suma);
			}
			else
				update(a + 1, 1);

			if (sumb != 0)
			{
				update(b, -sumb - 1);
				update(b + 1, sumb);
			}
			else
				update(b, -1);
		}
	}

	inline void update(int idx, int val)
	{
		for (int i = idx; i < mN; i += (i & -i))
			mFenwick[i] += val;
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
	ll mAns = 0;
	int mN = 100'001;
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