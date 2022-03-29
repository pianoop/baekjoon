//도로 네트워크
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef std::pair<int, int> pi;
typedef std::vector<pi> vpi;
typedef std::vector<vpi> vvpi;
typedef std::vector<int> vi;

class Tri
{
public:
	Tri() :par(-1), min(0), max(0) {}
	Tri(int p, int m, int M) :par(p), min(m), max(M) {}

	int par, min, max;
}; typedef std::vector<Tri> vT;

class LCA
{
public:
	LCA()
	{
		input();
		calc();
	}

	void PrintAns()
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
			int cnt = 0, min = 0x7FFFFFFF, max = 0;
			while (diff != 0)
			{
				if (diff & 1)
				{
					auto& tmp = mSparse[b][cnt];
					b = tmp.par;
					min = std::min(min, tmp.min);
					max = std::max(max, tmp.max);
				}
				diff >>= 1;
				cnt++;
			}

			if (a != b)
			{
				for (int j = mMaxsp; j >= 0; j--)
				{
					if (mSparse[a][j].par != mSparse[b][j].par)
					{
						min = std::min(min, mSparse[a][j].min);
						max = std::max(max, mSparse[a][j].max);
						a = mSparse[a][j].par;

						min = std::min(min, mSparse[b][j].min);
						max = std::max(max, mSparse[b][j].max);
						b = mSparse[b][j].par;
					}
				}
				min = std::min(min, mSparse[a][0].min);
				max = std::max(max, mSparse[a][0].max);

				min = std::min(min, mSparse[b][0].min);
				max = std::max(max, mSparse[b][0].max);
			}

			std::cout << min << " " << max << "\n";
		}
	}

private:
	void input()
	{
		std::cin >> mN;
		mMaxsp = int(floor(log2(mN)));
		mEdges.resize(mN + 1);
		mDepth.resize(mN + 1, -1);
		mSparse.resize(mN + 1, vT(mMaxsp + 1));
		int a, b, cost;
		for (int i = 1; i < mN; i++)
		{
			std::cin >> a >> b >> cost;
			mEdges[a].push_back({ b,cost });
			mEdges[b].push_back({ a,cost });
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
				auto& par = mSparse[i][sp - 1];
				if (par.par != -1)
				{
					auto& spar = mSparse[i][sp];
					auto& ppar = mSparse[par.par][sp - 1];
					spar.par = ppar.par;
					spar.max = std::max(par.max, ppar.max);
					spar.min = std::min(par.min, ppar.min);
				}
			}
		}
	}

	void calcRecur(int now)
	{
		int nextdepth = mDepth[now] + 1;
		for (const auto& p : mEdges[now])
		{
			if (mDepth[p.first] == -1)
			{
				mSparse[p.first][0] = { now,p.second,p.second };
				mDepth[p.first] = nextdepth;

				calcRecur(p.first);
			}
		}
	}

private:
	int mN, mMaxsp;
	std::vector<vT> mSparse;
	vvpi mEdges;
	vi mDepth;
};

void Solve()
{
	LCA Lca;
	Lca.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}