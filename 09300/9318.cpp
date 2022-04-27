//위성 사진
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

struct Data
{
	int x, y1, y2;
	bool sign;

	bool operator<(const Data& o) const
	{
		return x < o.x;
	}
};

class SegmentTree
{
public:
	SegmentTree()
	{
		solve();
	}

private:
	void solve()
	{
		mN = 1 << 21;
		mTree.resize(mN);
		mCnt.resize(mN);
		mN >>= 1;

		int n, x1, y1, x2, y2;
		std::cin >> n;
		std::vector<Data> mapes;
		mapes.reserve(n << 1);

		while (n--)
		{
			std::cin >> x1 >> y1 >> x2 >> y2;
			mapes.emplace_back(x1, ++y1, y2, true);
			mapes.emplace_back(x2, y1, y2, false);
		}

		std::sort(mapes.begin(), mapes.end());

		int nowx = mapes.front().x;
		long long ans = 0;
		for (auto& [x, y1, y2, sign] : mapes)
		{
			if (x != nowx)
			{
				ans += (x - nowx) * (long long)mTree[1];
				nowx = x;
			}

			if (sign)
				updateP(1, y1, y2, 1, mN);
			else
				updateN(1, y1, y2, 1, mN);
		}

		std::cout << ans<<"\n";
	}

	void updateP(int now, int l, int r, int s, int e)
	{
		if (s > r || e < l)
			return;

		if (l <= s && e <= r)
			mCnt[now]++;
		else
		{
			int m = s + (e - s) / 2, next = now << 1;
			updateP(next, l, r, s, m);
			updateP(next | 1, l, r, m + 1, e);
		}
		if (mCnt[now])
			mTree[now] = e - s + 1;
		else if (s != e)
		{
			int child = now << 1;
			mTree[now] = mTree[child] + mTree[child | 1];
		}
		else
			mTree[now] = 0;
	}

	void updateN(int now, int l, int r, int s, int e)
	{
		if (s > r || e < l)
			return;

		if (l <= s && e <= r)
			mCnt[now]--;
		else
		{
			int m = s + (e - s) / 2, next = now << 1;
			updateN(next, l, r, s, m);
			updateN(next | 1, l, r, m + 1, e);
		}

		if (mCnt[now])
			mTree[now] = e - s + 1;
		else if (s != e)
		{
			int child = now << 1;
			mTree[now] = mTree[child] + mTree[child | 1];
		}
		else
			mTree[now] = 0;
	}

private:
	vi mTree, mCnt;
	int mN;

};

void Solve()
{
	int n;
	std::cin >> n;
	while(n--)
		SegmentTree seg;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}