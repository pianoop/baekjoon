//아이돌
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
	SCC(int n) :mN(n)
	{
		input();
		calc();
	}

	~SCC()
	{
		delete[] mbCheck;
		delete[] mbSccCheck;
	}

	void PrintAns()
	{
		if (mbAns)
		{
			if (mTransSccidx[2] < mTransSccidx[3])
				std::cout << "yes\n";
			else
				std::cout << "no\n";
		}
		else
			std::cout << "no\n";
	}

private:
	void input()
	{
		int e;
		std::cin >> e;
		mN = (mN << 1) + 2;
		mGraph.resize(mN);

		int a, b;
		while (e--)
		{
			std::cin >> a >> b;
			if (a < 0)
			{
				a = (a * -1) << 1;
				if (b < 0)
				{
					b = (b * -1) << 1;
					mGraph[a].push_back(b + 1);
					mGraph[b].push_back(a + 1);
				}
				else
				{
					b <<= 1;
					mGraph[a].push_back(b);
					mGraph[b + 1].push_back(a + 1);
				}
			}
			else
			{
				a <<= 1;
				if (b < 0)
				{
					b = (b * -1) << 1;
					mGraph[a + 1].push_back(b + 1);
					mGraph[b].push_back(a);
				}
				else
				{
					b <<= 1;
					mGraph[a + 1].push_back(b);
					mGraph[b + 1].push_back(a);
				}
			}
		}
	}

	void calc()
	{
		mDisc.resize(mN, -1);
		mTransSccidx.resize(mN, -1);
		mbCheck = new bool[mN];
		memset(mbCheck, false, sizeof(bool) * mN);
		mbSccCheck = new bool[mN]();
		memset(mbSccCheck, false, sizeof(bool) * mN);

		int cnt = 0, scccnt = 0;
		for (int i = 2; i < mN; i++)
		{
			if (!mbCheck[i])
				tarjan(i, cnt, scccnt);

			if (!mbAns)
				break;
		}
	}

	int tarjan(int now, int& cnt, int& scccnt)
	{
		mSt.push(now);
		mbCheck[now] = true;
		int par = mDisc[now] = cnt++;

		for (auto& next : mGraph[now])
		{
			if (!mbCheck[next])
				par = std::min(par, tarjan(next, cnt, scccnt));
			else if (!mbSccCheck[next])
			{

				par = std::min(par, mDisc[next]);
			}
		}

		if (par == mDisc[now])
		{
			while (true)
			{
				int top = mSt.top();
				mSt.pop();

				if (top & 1)
				{
					if (mTransSccidx[top - 1] == scccnt)
						mbAns = false;
				}
				else
				{
					if (mTransSccidx[top + 1] == scccnt)
						mbAns = false;
				}

				mbSccCheck[top] = true;
				mTransSccidx[top] = scccnt;
				if (now == top)
					break;
			}

			scccnt++;
		}


		return par;
	}

private:
	bool mbAns = true;
	bool* mbCheck, * mbSccCheck;
	int mN;
	vi mDisc, mTransSccidx;
	vvi mGraph;
	std::stack<int> mSt;
};

void Solve()
{
	int n;
	while (std::cin >> n)
	{
		SCC scc(n);
		scc.PrintAns();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}