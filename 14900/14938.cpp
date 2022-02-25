//서강그라운드
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M, R;
	std::cin >> N >> M >> R;

	vi item(N + 1);
	std::for_each(item.begin() + 1, item.end(), [](auto& a)
		{
			std::cin >> a;
		});

	vvi route(N + 1, vi(N + 1, 16));
	for (int a, b, c, i = 0;i < R;i++)
	{
		std::cin >> a >> b >> c;
		route[a][b] = route[b][a] = c;
	}
	for (int i = 1;i < N + 1;i++)
		route[i][i] = 0;

	for (int m = 1;m < N + 1;m++)
	{
		for (int s = 1;s < N + 1;s++)
		{
			for (int f = 1;f < N + 1;f++)
			{
				route[s][f] = Min(route[s][f],route[s][m] + route[m][f]);
			}
		}
	}

	M++;
	int Max = 0;
	for (int i = 1;i < N + 1;i++)
	{
		int temp = 0;
		for (int j = 1;j < N + 1;j++)
		{
			if (route[i][j] < M)
				temp += item[j];
		}
		if (Max < temp)
			Max = temp;
	}

	std::cout << Max;

	return 0;
}