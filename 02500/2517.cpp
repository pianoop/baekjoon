//달리기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> pi;
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
		mFenwick.resize(mN + 1);
		std::vector<pi> status(mN);
		int order = 1;

		for (auto& [a, b] : status)
		{
			std::cin >> a;
			b = order++;
		}

		std::sort(status.begin(), status.end(), [](auto& stat1, auto& stat2)-> bool
			{
				return stat1.first <= stat2.first;
			});

		order = mN;
		for (auto& stat : status)
			stat.first = order--;

		std::sort(status.begin(), status.end(), [](auto& stat1, auto& stat2)->bool
			{
				return stat1.second < stat2.second;
			});

		update(1);
		for (auto& stat : status)
		{
			std::cout << sum(stat.first) << "\n";
			update(stat.first);
		}
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