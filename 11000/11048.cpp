//이동하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Tri
{
public:
	int r, c, cost;
};

void Solve()
{
	int n, m;
	std::cin >> n >> m;

	n++, m++;
	vvi map(n, vi(m)), dp(n, vi(m));
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			std::cin >> map[i][j];

	bool** bCheck = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		bCheck[i] = new bool[m];
		memset(bCheck[i], false, sizeof(bool) * m);
	}
	n--, m--;


	std::queue<Tri> box;
	box.push({ 1,1,map[1][1]});
	dp[1][1] = map[1][1];

	int nextr, nextc, nextCost;
	while (!box.empty())
	{
		auto [r, c, cost] = box.front();
		box.pop();
		if (cost < dp[r][c])
			continue;

		if (c < m)
		{
			nextc = c + 1;
			nextCost = cost + map[r][nextc];
			
			if (!bCheck[r][nextc] || nextCost > dp[r][nextc])
			{
				bCheck[r][nextc] = true;
				dp[r][nextc] = nextCost;
				box.push({ r,nextc,nextCost });
			}
		}

		if (r < n)
		{
			nextr = r + 1;
			nextCost = cost + map[nextr][c];

			if (!bCheck[nextr][c] || nextCost > dp[nextr][c])
			{
				bCheck[nextr][c] = true;
				dp[nextr][c] = nextCost;
				box.push({ nextr, c, nextCost });
			}
		}

	}

	std::cout << dp[n][m];

	for (int i = 0; i <= n; i++)
		delete[] bCheck[i];
	delete[] bCheck;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}