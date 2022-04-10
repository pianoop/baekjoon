//구간 합 구하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
typedef std::vector<ll> vl;

class SegmentTree
{
public:
	SegmentTree(int n)
	{
		input(n);
		mN--;  // -----------------!!!!mN 한칸 낮아진 것 확인!!!!---------------------
	}

	void Modify()
	{
		int a;
		ll b;
		std::cin >> a >> b;
		a += mN;

		ll modi = b - mSegTree[a];
		mSegTree[a] = b;
		for (a >>= 1; a > 0; a >>= 1)
			mSegTree[a] += modi;
	}

	void Query()
	{
		ll ans = 0;
		int l, r;
		std::cin >> l >> r;
		for (l += mN, r += mN + 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				ans += mSegTree[l++];
			if (r & 1)
				ans += mSegTree[--r];
		}
		
		std::cout << ans << "\n";
	}

private:
	void input(int n)
	{
		mN = 1 << int(ceil(log2(n)));
		mSegTree.resize(mN << 1);
		for (int i = mN; i < mN + n; i++)
			std::cin >> mSegTree[i];

		for (int i = mN - 1; i > 0; i--)
			mSegTree[i] = mSegTree[i << 1] + mSegTree[i << 1 | 1];
	}

private:
	vl mSegTree;
	int mN;

};

void Solve()
{
	int N, M, K;
	std::cin >> N >> M >> K;
	SegmentTree seg(N);
	M += K;

	while (M--)
	{
		std::cin >> K;

		if (K == 1)
			seg.Modify();
		else
			seg.Query();
	}

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}