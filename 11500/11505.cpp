//구간 곱 구하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
typedef std::vector<int> vi;

const int DEVIDE = 1'000'000'007;

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
		int a, b;
		std::cin >> a >> b;

		a += mN;
		mSegTree[a] = b;
		for (; a > 1; a >>= 1)
			mSegTree[a >> 1] = (ll(mSegTree[a]) * mSegTree[a^1]) % DEVIDE;
	}

	void Query()
	{
		ll ans = 1;
		int l, r;
		std::cin >> l >> r;
		for (l += mN, r += mN + 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				ans = (ans * mSegTree[l++]) % DEVIDE;
			if (r & 1)
				ans = (ans * mSegTree[--r]) % DEVIDE;
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
			mSegTree[i] = (ll(mSegTree[i << 1]) * mSegTree[i << 1 | 1]) % DEVIDE;
	}

private:
	vi mSegTree;
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