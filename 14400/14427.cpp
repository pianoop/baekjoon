//수열과 쿼리 15
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpi;


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
		int Q;
		cin >> Q;

		if (Q == 1)
			update();
		else
			printAns();
	}


private:
	void input(int n)
	{
		mN = 1 << int(ceil(log2(n)));
		mSegTree.resize(mN << 1, {0x7FFFFFFF, 0});

		int idx = 1;
		for_each(mSegTree.begin() + mN, mSegTree.begin() + mN + n, [&idx](auto& compo)
			{
				cin >> compo.first;
				compo.second = idx++;
			});

		for (int i = mN - 1; i > 0; i--)
		{
			int tmp = i << 1;
			mSegTree[i] = _min(mSegTree[tmp], mSegTree[tmp | 1]);
		}
	}

	void printAns()
	{
		cout << mSegTree[1].second << "\n";
	}

	void update()
	{
		int idx, val;
		cin >> idx >> val;

		idx += mN;
		mSegTree[idx].first = val;

		for (idx >>= 1; idx > 0; idx >>= 1)
		{
			int tmp = idx << 1;
			mSegTree[idx] = _min(mSegTree[tmp], mSegTree[tmp | 1]);
		}
	}

	inline pii& _min(pii& a, pii& b)
	{
		if (a.first < b.first)
			return a;
		else if (a.first == b.first)
		{
			if (a.second < b.second)
				return a;
			else
				return b;
		}
		else
			return b;
	}

private:
	vpi mSegTree;
	int mN;

};

void Solve()
{
	int N, M;
	std::cin >> N;
	SegmentTree seg(N);

	cin >> M;
	while (M--)
		seg.Query();

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}