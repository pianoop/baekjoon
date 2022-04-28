//직사각형
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::tuple<int, int, int, int> ti4;

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
		int n;
		std::cin >> n;
		std::vector<ti4> tmp(n);
		std::vector<int*> yposes;
		yposes.reserve(n);

		n <<= 1;
		mComp.reserve(n);
		std::vector<Data> mapes;
		mapes.reserve(n);

		for (auto& [x1, x2, y1, y2] : tmp)
		{
			std::cin >> x1 >> x2 >> y1 >> y2;
			yposes.emplace_back(&y1);
			yposes.emplace_back(&y2);
		}

		compress(yposes);

		for (auto& [x1, x2, y1, y2] : tmp)
		{
			y1 += mN, y2 += mN;
			mapes.push_back({ x1, y1, y2, true });
			mapes.push_back({ x2, y1, y2, false });
		}

		std::sort(mapes.begin(), mapes.end());

		long long ans = 0;
		int nowx = mapes.front().x;
		for (auto& [x, y1, y2, sign] : mapes)
		{
			if (x != nowx)
			{
				ans += (x - nowx) * (long long)mTree[1];

				nowx = x;
			}

			update(y1, y2, sign);
		}

		std::cout << ans << "\n";
	}

	void compress(std::vector<int*>& yposes)
	{
		std::sort(yposes.begin(), yposes.end(), [](auto a, auto b) -> bool
			{
				return *a < *b;
			});

		vi tmp;
		tmp.reserve(int(yposes.size()));
		int prev = *(yposes.front()), idx = 0;
		for (auto ypos : yposes)
		{
			if (prev != *ypos)
			{
				tmp.push_back(*ypos - prev);
				prev = *ypos;
				*ypos = ++idx;
			}
			else
				*ypos = idx;
		}
		mN = ((idx + 1) << 1) | 1;
		mComp.resize(mN);
		mTree.resize(mN);
		mCnt.resize(mN);

		mN = (mN >> 1) - 1;
		std::copy(tmp.begin(), tmp.end(), mComp.begin() + mN);

		for (int i = mN - 1; i > 0; i--)
		{
			int child = i << 1;
			mComp[i] = mComp[child] + mComp[child | 1];
		}
	}

	void update(int l, int r, bool sign) {
		int l0 = l, r0 = r;

		if (sign)
		{
			for (; l != r; l >>= 1, r >>= 1) {
				if (l & 1) applyP(l++);
				if (r & 1) applyP(--r);
			}
		}
		else
		{
			for (; l != r; l >>= 1, r >>= 1) {
				if (l & 1) applyN(l++);
				if (r & 1) applyN(--r);
			}
		}

		mTree[l0] = mCnt[l0] ? mComp[l0] : 0;
		mTree[r0] = mCnt[r0] ? mComp[r0] : 0;

		for (int i = l0 >> 1; i > 0; i >>= 1)
		{
			int child = i << 1;
			mTree[i] = mCnt[i] ? mComp[i] : mTree[child] + mTree[child | 1];
		}

		for (int i = r0 >> 1; i > 0; i >>= 1)
		{
			int child = i << 1;
			mTree[i] = mCnt[i] ? mComp[i] : mTree[child] + mTree[child | 1];
		}
	}

	inline void applyP(int i) {
		mCnt[i]++;
		mTree[i] = mComp[i];
	}
	
	inline void applyN(int i) {
		int child = i << 1;
		mTree[i] = --mCnt[i] ? mComp[i] : i < mN ? mTree[child] + mTree[child | 1] : 0;
	}

private:
	vi mTree, mComp, mCnt;
	int mN;

};

void Solve()
{
	SegmentTree seg;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}