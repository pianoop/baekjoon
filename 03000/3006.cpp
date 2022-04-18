//터보소트
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Fenwick
{
public:
	Fenwick(int n) :mN(n)
	{
		solve();
	}

private:
	void solve()
	{
		mFenwick.resize(mN + 1, 1);
		mFenwick[1] = 0;
		int tmp;
		for (int i = 2; i <= mN; i++)
		{
			tmp = i + (i & -i);
			if (tmp <= mN)
				mFenwick[tmp] += mFenwick[i];
		}


		vi trans(mN + 1);
		for (int i = 1; i <= mN; i++)
		{
			std::cin >> tmp;
			trans[tmp] = i;
		}

		int j = mN, total = mN - 2, i;
		for (i = 1; i <= mN/2; i++, j--)
		{
			int &nowf = trans[i], &nowb = trans[j];
			std::cout << sum(nowf) << "\n";
			update(nowf);

			std::cout << total - sum(nowb) << "\n";
			update(nowb);
			
			total -= 2;
		}

		if (mN & 1)
		{
			std::cout << sum(trans[i]);
		}
	}

	inline void update(int idx)
	{
		for (int i = idx; i <= mN; i += (i & -i))
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
	int mN;

};

void Solve()
{
	int N;
	std::cin >> N;

	Fenwick fen(N);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}