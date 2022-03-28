//LCA2
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

	void PrintLCA()
	{
		int n, a, b;
		std::cin >> n;
		//lca
		while (n--)
		{
			std::cin >> a >> b;
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

			std::cout << a << "\n";
		}
	}

private:
	void input()
	{
		std::cin >> mN;
		mMaxsp = int(floor(log2(mN)));
		mEdges.resize(mN + 1);
		mDepth.resize(mN + 1, -1);
		mSparse.resize(mN+1,vi(mMaxsp + 1 , -1));
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
		{
			for (int i = 1; i <= mN; i++)
			{
				int par = mSparse[i][sp - 1];
				if(par != -1)
					mSparse[i][sp] = mSparse[par][sp - 1];
			}
		}
	}

	void calcRecur(int now)
	{
		int nextdepth = mDepth[now] + 1;
		for (auto& node : mEdges[now])
		{
			if (mDepth[node] == -1)
			{
				mSparse[node][0] = now;
				mDepth[node] = nextdepth;

				calcRecur(node);
			}
		}
	}

private:
	int mN, mMaxsp;
	vvi mSparse, mEdges;
	vi mDepth;
};

void Solve()
{
	LCA Lca;
	Lca.PrintLCA();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}