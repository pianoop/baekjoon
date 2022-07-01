//단절점
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		for (int i = 1; i <= mV; i++)
		{
			if(mCheck[i] < 0)
				recur1(i);
		}

		cout << mAns << "\n";
		for (int i = 1; i <= mV; i++)
		{
			if (mCut[i] >= 0)
				cout << i << " ";
		}
	}


private:
	void input()
	{
		int E, a, b;
		cin >> mV >> E;

		mEdges.resize(mV + 1);
		mCut.resize(mV + 1, -1);
		mCheck.resize(mV + 1, -1);
		while (E--)
		{
			cin >> a >> b;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
		}
	}

	int recur1(int now)
	{
		int Min, ch = 0;
		Min = mCheck[now] = ++mCnt;

		for (auto next : mEdges[now])
		{
			if (mCheck[next] < 0)
			{
				int tmp = recur2(next);
				ch++;

				Min = min(Min, tmp);
			}
			else
				Min = min(Min, mCheck[next]);
		}

		if (ch >= 2)
		{
			mAns++;
			mCut[now] = 0;
		}

		return Min;
	}

	int recur2(int now)
	{
		int Min;
		Min = mCheck[now] = ++mCnt;

		for (auto next : mEdges[now])
		{
			if (mCheck[next] < 0)
			{
				int tmp = recur2(next);

				if (tmp >= mCheck[now] && mCut[now] == -1)
				{
					mCut[now] = 0;
					mAns++;
				}

				Min = min(Min, tmp);
			}
			else
				Min = min(Min, mCheck[next]);
		}
		

		return Min;
	}

private:
	vvi mEdges;
	vi mCheck, mCut;
	int mV, mAns = 0, mCnt = 0;

};


void Solve()
{
	Q q;
	q.Solve();
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}