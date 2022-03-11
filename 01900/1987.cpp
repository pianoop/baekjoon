//알파벳
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<bool> vb;

std::pair<int, int> arrow[4] = { {-1,0},{1,0},{0,-1},{0,1} };

class AlphaBoard
{
public:
	AlphaBoard()
	{
		memset(mbit, true, sizeof(mbit));
	}

	void Input()
	{
		int n, m;
		std::cin >> n >> m;
		mBoard.resize(n + 2, vi(m + 2, -1));
		char temp;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				std::cin >> temp;
				mBoard[i][j] = int(temp) - 65;
			}
		}
		mbit[mBoard[1][1]] = false;
	}

	int BackTracking(int n, int m, int nowcnt)
	{
		int ans = nowcnt;
		for (int i = 0; i < 4; i++)
		{
			int nextn = n + arrow[i].first, nextm= m + arrow[i].second;
			if (mBoard[nextn][nextm] < 0)
				continue;

			if (mbit[mBoard[nextn][nextm]])
			{
				mbit[mBoard[nextn][nextm]] = false;
				ans = std::max(ans, BackTracking(nextn, nextm, nowcnt+1));
				mbit[mBoard[nextn][nextm]] = true;
			}
		}

		return ans;
	}

private:
	vvi mBoard;
	bool mbit[26];
};

void Solve()
{
	AlphaBoard Alpha;
	Alpha.Input();
	printf("%d", Alpha.BackTracking(1, 1, 1));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}