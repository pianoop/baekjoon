//구간 합 구하기 5
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	vvi table(N+1, vi(N+1));
	std::for_each(table.begin() + 1, table.end(), [](auto& a)
		{
			std::for_each(a.begin() + 1, a.end(), [](auto& b)
				{
					std::cin >> b;
				});
		});

	for (int i = 1;i < N + 1;i++)
	{
		for (int j = 1;j < N + 1;j++)
		{
			table[i][j] += table[i - 1][j] + table[i][j - 1]-table[i-1][j-1];
		}
	}

	int a, b, c, d;
	while (M--)
	{
		std::cin >> a >> b >> c >> d;
		std::cout << table[c][d] - table[a - 1][d] - table[c][b - 1] + table[a - 1][b - 1] << "\n";
	}

	return 0;
}