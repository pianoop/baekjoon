//적록색약
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int nx[4] = { -1,1,0,0 };
int ny[4] = { 0,0,-1,1 };

void DFS(int x, int y, const vvc& p, vvi& c)
{
	if (p[x][y] == 'B')
		c[x][y] = 2;
	else
		c[x][y] = 3;
	for (int nx1, ny1, i = 0;i < 4;i++)
	{
		nx1 = x + nx[i], ny1 = y + ny[i];
		if (c[nx1][ny1] == 1 && p[x][y] == p[nx1][ny1])
		{
			DFS(nx1, ny1, p, c);
		}
	}

}

void DFS2(int x, int y, const vvi& cp, vvi& c2)
{
	c2[x][y] = 0;
	for (int nx1, ny1, i = 0;i < 4;i++)
	{
		nx1 = x + nx[i], ny1 = y + ny[i];
		if (c2[nx1][ny1] == 1 && cp[x][y] == cp[nx1][ny1])
		{
			DFS2(nx1, ny1, cp, c2);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int ans1 = 0, ans2 = 0;
	vvi check(N + 2, vi(N + 2));
	vvi check2;
	{
		vvc paint(N + 2, vc(N + 2));
		for (int i = 1; i <= N;i++)
		{
			for (int j = 1;j <= N;j++)
			{
				std::cin >> paint[i][j];
				check[i][j] = 1;
			}
		}
		check2 = check;
		for (int i = 1; i <= N;i++)
		{
			for (int j = 1;j <= N;j++)
			{
				if (check[i][j] == 1)
				{
					ans1++;
					DFS(i, j, paint, check);
				}
			}
		}
	}
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			if (check2[i][j] == 1)
			{
				ans2++;
				DFS2(i, j, check,check2);
			}
		}
	}

	std::cout << ans1 << " " << ans2;

	return 0;
}