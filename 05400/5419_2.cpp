//북서풍 
//Fenwick tree
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef std::pair<int, int> pi;
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
		std::cin >> mN;

		std::vector<pi> pos2D(mN);
		for (auto& [a, b] : pos2D)
			std::cin >> a >> b;

		std::sort(pos2D.begin(), pos2D.end(), [](pi& a, pi& b) -> bool
			{
				return a.second < b.second;
			});

		int order = 1;
		for(int i = 1; i < mN; i++)
		{
			if (pos2D[i - 1].second != pos2D[i].second)
			{
				pos2D[i - 1].second = order;
				order++;
			}
			else
				pos2D[i - 1].second = order;
		}
		pos2D.back().second = order;

		mN = order;
		mTree.resize(mN + 1);

		std::sort(pos2D.begin(), pos2D.end(), [](pi& a, pi& b) -> bool
			{
				if (a.first == b.first)
					return a.second < b.second;
				return a.first > b.first;
			});

		mAns = 0;

		for (auto& [a,b] : pos2D)
		{
			sum(b);
			update(b);
		}

		std::cout << mAns << "\n";
	}

	inline void update(int idx)
	{
		for (; idx <= mN; idx += idx & -idx)
			mTree[idx]++;
	}

	inline void sum(int idx)
	{
		for (; idx > 0; idx -= idx & -idx)
			mAns += mTree[idx];
	}

private:
	int mN;
	long long mAns = 0;
	vi mTree;
};

void Solve()
{
	int T;
	std::cin >> T;
	while (T--)
		Fenwick fen;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}