//축구 전술
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
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
		if (mAns.empty())
			std::cout << "Confused\n";
		else
		{
			std::sort(mAns.begin(), mAns.end());
			for (auto& ans : mAns)
				std::cout << ans << "\n";
		}
		std::cout << "\n";
	}

private:
	void input()
	{
		int e;
		std::cin >> mN >> e;
		mGraph.resize(mN);
		mRevGraph.resize(mN);
		mbCheck = new bool[mN];
		memset(mbCheck, false, sizeof(bool) * (mN));

		int a, b;
		while (e--)
		{
			std::cin >> a >> b;
			mGraph[a].push_back(b);
			mRevGraph[b].push_back(a);
		}

	}

	void calc()
	{
		for (int i = 0; i < mN; i++)
		{
			if (!mbCheck[i])
				dfs1(i);
		}

		memset(mbCheck, false, sizeof(bool) * (mN));
		int top = mSt.top();
		bool endflag = false;
		while (!mSt.empty())
		{
			if (!mbCheck[mSt.top()])
			{
				if (endflag)
					return;

				endflag = true;
				dfs2(mSt.top());
			}

			mSt.pop();
		}

		memset(mbCheck, false, sizeof(bool) * (mN));

		dfs3(top);
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
	void dfs3(int now)
	{
		mbCheck[now] = true;
		mAns.push_back(now);

		for (auto& next : mRevGraph[now])
		{
			if (!mbCheck[next])
				dfs3(next);
		}
	}

private:
	bool* mbCheck;
	int mN;
	vi mAns;
	vvi mGraph, mRevGraph;
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
	while (T--)
		Solve();

	return 0;
}