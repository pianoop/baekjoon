//Egg
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;

class Pos
{
public:
	int x, y1, y2;
	bool sign;

	bool operator<(const Pos& Other) const
	{
		if (x == Other.x)
			return sign > Other.sign;
		return x < Other.x;
	}
};

class Egg
{
public:
	Egg()
	{
		input();
	}

	void Solve()
	{
		int endR = (int)mRanges.size();

		int i = 0;
		for (auto& [x, y] : mPeople)
		{
			while (x >= mRanges[i].x && (x != mRanges[i].x || mRanges[i].sign))
			{
				update(mRanges[i].y1, mRanges[i].y2, mRanges[i].sign);

				if (++i == endR) //mRanges.end()
				{
					std::cout << mAns << "\n";
					return;
				}
			}

			sum(y);
		}

		std::cout << mAns << "\n";
	}

private:
	void input()
	{
		mTree.resize(2'097'152); // 1 << 21 (= mN << 1)

		int N, M;
		std::cin >> N >> M;
		mRanges.reserve((M << 1));
		mPeople.resize(N);

		for (auto& [x, y] : mPeople)
		{
			std::cin >> x >> y;
			y += mN;
		}

		int x1, x2, y1, y2;
		for (int i = 0; i < M; i++)
		{
			std::cin >> x1 >> x2 >> y1 >> y2;
			y1 += mN, y2 += mN + 1;
			mRanges.push_back({ x1, y1, y2, true });
			mRanges.push_back({ x2, y1, y2, false });
		}
	
		std::sort(mPeople.begin(), mPeople.end(), [](auto& A, auto& B)->bool
			{
				return A.first < B.first;
			});

		std::sort(mRanges.begin(), mRanges.end());
	}

	void update(int l, int r, bool sign)
	{
		if (sign)
		{
			for (; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1) mTree[l++]++;
				if (r & 1) mTree[--r]++;
			}
		}
		else
		{
			for (; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1) mTree[l++]--;
				if (r & 1) mTree[--r]--;
			}
		}
	}

	void sum(int i)
	{
		for (; i > 0; i >>= 1)
			mAns += mTree[i];
	}

private:
	std::vector<Pos> mRanges;
	std::vector<pi> mPeople;
	vi mTree;
	int mAns = 0, mN = 1'048'576; //1<<20
};

void Solve()
{
	Egg Q;
	Q.Solve();
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