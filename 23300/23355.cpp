//공사
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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

	void Query1()
	{
		int a, b, k;
		std::cin >> a >> b >> k;

		int ParDepthAB = mDepth[findLCA(a, b)];

		if (mDepth[k] < ParDepthAB)
			std::cout << "YES\n";
		else if(findLCA(a,k) == k || findLCA(b,k) == k)
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}

	void Query2()
	{
		int a, b, k, l;
		std::cin >> a >> b >> k >> l;

		int ParDepthAB = mDepth[findLCA(a, b)];

		if(mDepth[k] <= ParDepthAB && mDepth[l] <= ParDepthAB)
			std::cout << "YES\n";
		else
		{
			int parABK = findLCA(a, k), parABL = findLCA(a,l);
			if ((parABK == k && parABL == l) || (parABK == l && parABL == k))
			{
				std::cout << "NO\n";
				return;
			}
			
			parABK = findLCA(b, k), parABL = findLCA(b, l);
			if ((parABK == k && parABL == l) || (parABK == l && parABL == k))
			{
				std::cout << "NO\n";
				return;
			}

			std::cout << "YES\n";
		}
	}

private:
	void input()
	{
		std::cin >> mN;
		mMaxsp = int(floor(log2(mN)));
		mEdges.resize(mN + 1);
		mDepth.resize(mN + 1, -1);
		mSparse.resize(mN + 1, vi(mMaxsp + 1));
		int a, b;
		for (int i = 1; i < mN; i++)
		{
			std::cin >> a >> b;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
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
		for (auto& node : mEdges[now])
		{
			if (mDepth[node] == -1)
			{
				mSparse[node][0] = now;
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
	vvi mSparse, mEdges;
	vi mDepth;
};

void Solve()
{
	LCA Lca;

	int M, query;
	std::cin >> M;
	while (M--)
	{
		std::cin >> query;
		if (query == 1)
			Lca.Query1();
		else
			Lca.Query2();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}