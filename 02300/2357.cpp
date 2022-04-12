//최솟값과 최댓값
//-------------------------------------------------------------------
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef std::vector<std::pair<int, int> > vpi;

class SegmentTree
{
public:
	SegmentTree(int n)
	{
		input(n);
		mN--;  // -----------------!!!!mN 한칸 낮아진 것 확인!!!!---------------------
	}

	void Query()
	{
		int min = 0x7FFFFFFF, max = 0;
		int l, r;
		std::cin >> l >> r;
		for (l += mN, r += mN + 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
			{
				min = std::min(min, mSegTree[l].first);
				max = std::max(max, mSegTree[l++].second);
			}

			if (r & 1)
			{
				min = std::min(min, mSegTree[--r].first);
				max = std::max(max, mSegTree[r].second);
			}
		}
		
		std::cout << min << " " << max << "\n";
	}

private:
	void input(int n)
	{
		mN = 1 << int(ceil(log2(n)));
		mSegTree.resize(mN << 1);
		std::for_each(mSegTree.begin() + mN, mSegTree.begin() + mN + n, [](auto& compo)
		{
				std::cin >> compo.first;
				compo.second = compo.first;
		});

		for (int i = mN - 1; i > 0; i--)
		{
			auto &a = mSegTree[i << 1], &b = mSegTree[i << 1 | 1];
			mSegTree[i] = { std::min(a.first, b.first), std::max(a.second, b.second) };
		}
	}

private:
	vpi mSegTree;
	int mN;

};

void Solve()
{
	int N, M;
	std::cin >> N >> M;
	SegmentTree seg(N);

	while (M--)
		seg.Query();

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}