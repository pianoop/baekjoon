//도미노
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class SCC
{
public:
	SCC()
	{
		input();
		calc();
	}

	~SCC()
	{
		delete[] mbCheck;
	}

	void PrintAns()
	{
		std::cout << mAns << "\n";
	}

private:
	void input()
	{
		int e;
		std::cin >> mN >> e;
		mGraph.resize(mN + 1);
		mbCheck = new bool[mN + 1];
		memset(mbCheck, false, sizeof(bool) * (mN + 1));

		int a, b;
		while (e--)
		{
			std::cin >> a >> b;
			mGraph[a].push_back(b);
		}

	}

	void calc()
	{
		for (int i = 1; i <= mN; i++)
		{
			if(!mbCheck[i])
				dfs1(i);
		}

		memset(mbCheck, false, sizeof(bool) * (mN + 1));

		while (!mSt.empty())
		{
			if (!mbCheck[mSt.top()])
			{
				mAns++;
				dfs2(mSt.top());
			}

			mSt.pop();
		}
	}

	void dfs1(int now)
	{
		mbCheck[now] = true;

		for (auto& next : mGraph[now])
		{
			if (!mbCheck[next])
				dfs1(next);
		}

		mSt.push(now);
	}

	void dfs2(int now)
	{
		mbCheck[now] = true;

		for (auto& next : mGraph[now])
		{
			if (!mbCheck[next])
				dfs2(next);
		}
	}

private:
	bool* mbCheck;
	int mN, mAns = 0;
	vvi mGraph;
	std::stack<int> mSt;
};

void Solve()
{
	SCC scc;
	scc.PrintAns();
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