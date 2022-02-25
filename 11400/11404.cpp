//플로이드
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int Max = 10000001;
	int N, M;
	std::cin >> N >> M;

	vvi bus(N + 1, vi(N + 1,Max));
	for (int a, b, c, i = 0;i < M;i++)
	{
		std::cin >> a >> b >> c;
		if (bus[a][b] > c)
			bus[a][b] = c;
	}
	for (int i = 0;i < N + 1;i++)
		bus[i][i] = 0;

	for (int m = 1;m < N + 1;m++)
	{
		for (int s = 1;s < N + 1;s++)
		{
			for (int f = 1;f < N + 1;f++)
			{
				bus[s][f] = Min(bus[s][f], bus[s][m] + bus[m][f]);
			}
		}
	}

	for (int i = 1;i < N + 1;i++)
	{
		for (int j = 1;j < N + 1;j++)
		{
			if (bus[i][j] >= Max)
				std::cout << "0 ";
			else
				std::cout << bus[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}