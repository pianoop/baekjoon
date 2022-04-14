//디지털 비디오 디스크(DVDs)
//------------------------------------------------------------------- 
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
		mN;
	}

	void Update()
	{
		int a, b;
		std::cin >> a >> b;

		a += mN, b += mN;
		std::swap(mSegTree[a], mSegTree[b]);
		for (; a > 1; a >>= 1)
		{
			auto &A = mSegTree[a], &B = mSegTree[a^1];
			mSegTree[a >> 1] = { std::min(A.first,B.first), std::max(A.second,B.second) };
		}

		for (; b > 1; b >>= 1)
		{
			auto& A = mSegTree[b], & B = mSegTree[b ^ 1];
			mSegTree[b >> 1] = { std::min(A.first,B.first), std::max(A.second,B.second) };
		}
	}

	void Query()
	{
		int min = 0x7FFFFFFF, max = -1;
		int l, r;
		std::cin >> l >> r;
		for (int L = l + mN, R = r + mN + 1; L < R; L >>= 1, R >>= 1)
		{
			if (L & 1)
			{
				min = std::min(min, mSegTree[L].first);
				max = std::max(max, mSegTree[L++].second);
			}

			if (R & 1)
			{
				min = std::min(min, mSegTree[--R].first);
				max = std::max(max, mSegTree[R].second);
			}
		}

		if (l == min && r == max)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

private:
	void input(int n)
	{
		mN = 1 << int(ceil(log2(n)));
		mSegTree.resize(mN << 1);

		int order = 0;
		std::for_each(mSegTree.begin() + mN, mSegTree.begin() + mN + n, [&order](auto& compo)
			{
				compo.first = compo.second = order++;
			});

		for (int i = mN - 1; i > 0; i--)
		{
			mSegTree[i] = { mSegTree[i << 1].first, std::max(mSegTree[i << 1].second, mSegTree[i << 1 | 1].second) };
		}
	}

private:
	vpi mSegTree;
	int mN;

};

void Solve()
{
	int N, M, q;
	std::cin >> N >> M;
	SegmentTree seg(N);

	while (M--)
	{
		std::cin >> q;
		if (q == 0)
			seg.Update();
		else
			seg.Query();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int T;
	std::cin >> T;

	while(T--)
		Solve();

	return 0;
}