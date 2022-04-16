//공장
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef long long ll;
typedef std::vector<int> vi;

class Fenwick
{
public:
	Fenwick(int n) :mN(n)
	{
		input();
	}

	void Query()
	{
		std::cout << mAns;
	}

private:
	void input()
	{
		mFenwick.resize(mN + 1);
		int tmp, order = mN;
		
		int* orderTable = new int[1'000'001];
		memset(orderTable, 0, sizeof(orderTable));
		for (int i = 0; i < mN; i++)
		{
			std::cin >> tmp;
			orderTable[tmp] = order--;
		}
		
		for (int i = 0; i < mN; i++)
		{
			std::cin >> tmp;
			tmp = orderTable[tmp];

			mAns += sum(tmp);
			update(tmp);
		}

		delete[] orderTable;
	}

	inline void update(int idx)
	{
		for (int i = idx; i <= mN; i += (i & -i))
			mFenwick[i]++;
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