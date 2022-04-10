//TV Show Game
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
			for (int i = 2; i < mN; i += 2)
			{
				std::cout << (mTransSccidx[i] < mTransSccidx[i + 1] ? "B" : "R");
			}
		}
		else
			std::cout << -1;
	}

private:
	void input()
	{
		int e;
		std::cin >> mN >> e;
		mN = mN * 2 + 2;
		mGraph.resize(mN);

		int A1, B1, C1, A2, B2, C2;
		int lampA, lampB, lampC;
		char colorA, colorB, colorC;
		while (e--)
		{
			std::cin >> lampA >> colorA >> lampB >> colorB >> lampC >> colorC;

			if (colorA == 'R')
			{	
				A1 = lampA * 2;	
				A2 = A1 + 1; 
			}
			else
			{	
				A2 = lampA * 2;
				A1 = A2 + 1;
			}
			//B, C도 A와 동일한 작업
			if (colorB == 'R') {	B1 = lampB * 2;	B2 = B1 + 1; }
			else {	B2 = lampB * 2;	B1 = B2 + 1; }
			if (colorC == 'R') {	C1 = lampC * 2;	C2 = C1 + 1; }
			else {	C2 = lampC * 2;	C1 = C2 + 1; }
			
			mGraph[A1].push_back(B2); 
			mGraph[A1].push_back(C2);
			mGraph[B1].push_back(A2); mGraph[B1].push_back(C2);
			mGraph[C1].push_back(A2); mGraph[C1].push_back(B2);
		}
	}

	void calc()
	{
		mDisc.resize(mN, -1);
		mTransSccidx.resize(mN, -1);
		mbCheck = new bool[mN]();
		mbSccCheck = new bool[mN]();

		int cnt = 0, scccnt = 0;
		for (int i = 2; i < mN; i++)
		{
			if (mbAns && !mbCheck[i])
				tarjan(i, cnt, scccnt);
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
	SCC scc;
	scc.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}