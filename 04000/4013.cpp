//ATM
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
		drive(mTransSccidx[mStart]);
	}
	
	~SCC()
	{
		delete[] mbFin;
		delete[] mRest;
		delete[] mSccRest;
	}

	void PrintAns()
	{
		std::cout << mDriveDP[mTransSccidx[mStart]];
	}

private:
	void input()
	{
		int v, e;
		std::cin >> v >> e;
		mGraph.resize(v + 1);
		mTransSccidx.resize(v + 1);

		int a, b;
		while (e--)
		{
			std::cin >> a >> b;
			mGraph[a].push_back(b);
		}
		
		mCost.resize(v + 1);
		for (int i = 1; i <= v; i++)
			std::cin >> mCost[i];

		mbFin = new bool[v + 1];
		mRest = new bool[v + 1];
		mSccRest = new bool[v + 1];
		memset(mbFin, false, sizeof(bool) * (v + 1));
		memset(mRest, false, sizeof(bool) * (v + 1));
		memset(mSccRest, false, sizeof(bool) * (v + 1));
		
		int rest, tmp;
		std::cin >> mStart >> rest;
		while (rest--)
		{
			std::cin >> tmp;
			mRest[tmp] = true;
		}
	}

	void calc()
	{
		int v = int(mGraph.size()) - 1;
		int cnt = 0, scccnt = 0;
		mDisc.resize(v + 1, -1);
		mSccCost.resize(v);

		for (int i = 1; i <= v; i++)
		{
			if (mDisc[i] == -1)
				dfs(i, cnt, scccnt);
		}

		mSccGraph.resize(scccnt);
		mDriveDP.resize(scccnt, -1);
		
		for (int i = 1; i <= v; i++)
		{
			int a = mTransSccidx[i];
			for (auto& next : mGraph[i])
			{
				int& b = mTransSccidx[next];

				if (a != b)
				{
					mSccGraph[a].push_back(b);
				}
			}
		}
	}

	int dfs(int now, int& cnt, int& scccnt)
	{
		stack.push(now);
		int par = mDisc[now] = cnt++;

		for (const auto& next : mGraph[now])
		{
			if (mDisc[next] == -1)
				par = std::min(par, dfs(next, cnt, scccnt));
			else if (!mbFin[next])
				par = std::min(par, mDisc[next]);
		}


		if (par == mDisc[now])
		{
			while (true)
			{
				mbFin[stack.top()] = true;

				mSccCost[scccnt] += mCost[stack.top()]; //

				mTransSccidx[stack.top()] = scccnt;

				if (mRest[stack.top()])
					mSccRest[scccnt] = true;

				if (stack.top() == now)
				{
					stack.pop();
					break;
				}
				stack.pop();
			}

			scccnt++;
		}

		return par;
	}
	
	void drive(int now) //cssDfs
	{
		int total = 0;

		for (auto& next : mSccGraph[now])
		{
			if (mDriveDP[next] == -1)
				drive(next);

			if (mSccRest[next])
			{
				mSccRest[now] = true;
				total = std::max(total, mDriveDP[next]);
			}
		}
		
		if (mSccRest[now])
			mDriveDP[now] = total + mSccCost[now];
		else
			mDriveDP[now] = 0;
	}

private:
	std::stack<int> stack;
	vvi mGraph, mSccGraph;
	vi mDisc, mSccCost, mCost, mTransSccidx, mDriveDP;
	int mStart, mAns = 0;
	bool *mbFin, *mRest, *mSccRest;
	
};

void Solve()
{
	SCC mSccCost;
	mSccCost.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}