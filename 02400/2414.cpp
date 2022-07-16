//게시판 구멍 막기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int cnt = 0;
		for (int i = 0; i < mC; i++)
		{
			fill(mCheck.begin(), mCheck.end(), 0);
			if (dfs(i))
				cnt++;
		}

		cout << cnt;
	}


private:
	void init()
	{
		int N, M;
		cin >> N >> M;
		
		int cntC = 0, cnt = -1, prevX = 0;
		vector<pii> idxCol(M);
		mEdges.resize(M * ((N >> 1) + 1));

		char c;
		for (int i = 0; i < N; i++)
		{
			prevX = 0;

			for (int j = 0; j < M; j++)
			{
				auto& now = idxCol[j];
				cin >> c;
				
				if (c != '.')
				{
					if (now.second < 0)
					{
						if (prevX < 0)
							mEdges[now.first].push_back(cnt);
						else
						{
							mEdges[now.first].push_back(++cnt);
							prevX = -1;
						}
					}
					else
					{
						now.first = cntC++;

						if (prevX < 0)
							mEdges[now.first].push_back(cnt);
						else
						{
							mEdges[now.first].push_back(++cnt);
							prevX = -1;
						}

						now.second = -1;
					}
				}
				else
				{
					now.second = 0;
					prevX = 0;
				}
			}
		}

		mC = cntC;
		mCnt = cnt + 1;
		mCheck.resize(mC);
		mPartner.resize(cnt + 1, -1);
	}

	bool dfs(int now)
	{
		if (mCheck[now] < 0)
			return false;
		mCheck[now] = -1;

		for (auto next : mEdges[now])
		{
			if (mPartner[next] < 0 || dfs(mPartner[next]))
			{
				mPartner[next] = now;
				return true;
			}
		}

		return false;
	}


private:
	vvi mEdges;
	vi mPartner, mCheck;
	int mC, mCnt;

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