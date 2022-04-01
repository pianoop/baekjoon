//개미
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef std::vector<pi> vpi;
typedef std::vector<vpi> vvpi;

class Sparse
{
public:
	Sparse()
	{
		input();
		calc();
	}

	void PrintAns()
	{
		for (int i = 1; i <= mN; i++)
			move(i, mEnerges[i]);
	}

private:
	void input()
	{
		std::cin >> mN;
		mMaxsp = int(floor(log2(mN)));
		mSparse.resize(mN + 1, vpi(mMaxsp + 1));

		mEnerges.resize(mN + 1);
		for (int i = 1; i <= mN; i++)
			std::cin >> mEnerges[i];

		mEdges.resize(mN + 1);
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
		calcRecur(1, 0);

		for (int sp = 1; sp <= mMaxsp; sp++)
		{
			for (int i = 1; i <= mN; i++)
			{
				auto& par = mSparse[i][sp - 1];

				mSparse[i][sp].first = mSparse[par.first][sp - 1].first;
				mSparse[i][sp].second = mSparse[par.first][sp - 1].second + par.second;
			}
		}
	}

	void calcRecur(int now, int par)
	{
		for (auto& [node, cost] : mEdges[now])
		{
			if (node != par)
			{
				mSparse[node][0].first = now;
				mSparse[node][0].second = cost;
				calcRecur(node, now);
			}
		}
	}

	void move(int a, int e)
	{
		for (int j = mMaxsp; j >= 0 && e; j--)
		{
			if (mSparse[a][j].first != 0 && mSparse[a][j].second <= e)
			{
				e -= mSparse[a][j].second;
				a = mSparse[a][j].first;
			}
		}

		std::cout << a << "\n";
	}

private:
	int mN, mMaxsp;
	vvpi mEdges, mSparse;
	vi mEnerges;
};

void Solve()
{
	Sparse sp;
	sp.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}