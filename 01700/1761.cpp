//정점들의 거리
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef std::pair<int, int> pi;
typedef std::vector<pi> vpi;
typedef std::vector<vpi> vvpi;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class LCA
{
public:
	LCA()
	{
		input();
		calc();
	}

	void PrintCost()
	{
		int a, b;
		std::cin >> a >> b;

		std::cout << mCost[a] + mCost[b] - 2 * mCost[findLCA(a, b)] << "\n";
	}

private:
	void input()
	{
		std::cin >> mN;
		mMaxsp = int(floor(log2(mN)));
		mEdges.resize(mN + 1);
		mCost.resize(mN + 1);
		mDepth.resize(mN + 1, -1);
		mSparse.resize(mN + 1, vi(mMaxsp + 1));
		int a, b, cost;
		for (int i = 1; i < mN; i++)
		{
			std::cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mEdges[b].push_back({ a, cost });
		}
	}

	void calc()
	{
		mDepth[1] = 0;
		calcRecur(1);

		for (int sp = 1; sp <= mMaxsp; sp++)
			for (int i = 1; i <= mN; i++)
				mSparse[i][sp] = mSparse[mSparse[i][sp - 1]][sp - 1];
	}

	void calcRecur(int now)
	{
		for (auto& [node, cost] : mEdges[now])
		{
			if (mDepth[node] == -1)
			{
				mSparse[node][0] = now;
				mCost[node] = mCost[now] + cost;
				mDepth[node] = mDepth[now] + 1;

				calcRecur(node);
			}
		}
	}

	int findLCA(int a, int b)
	{
		if (mDepth[a] > mDepth[b])
			std::swap(a, b);

		int diff = mDepth[b] - mDepth[a];
		int cnt = 0;
		while (diff != 0)
		{
			if (diff & 1)
				b = mSparse[b][cnt];

			diff >>= 1;
			cnt++;
		}

		if (a != b)
		{
			for (int j = mMaxsp; j >= 0; j--)
			{
				if (mSparse[a][j] != mSparse[b][j])
				{
					a = mSparse[a][j];
					b = mSparse[b][j];
				}
			}
			a = mSparse[a][0];
		}

		return a;
	}

private:
	int mN, mMaxsp;
	vvpi mEdges;
	vvi mSparse;
	vi mDepth, mCost;
};

void Solve()
{
	LCA Lca;

	int M;
	std::cin >> M;
	while (M--)
		Lca.PrintCost();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}