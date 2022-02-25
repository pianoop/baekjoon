//운동
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int Max = 100000001;
	int N, M;
	std::cin >> N >> M;

	vvi road(N + 1, vi(N + 1, Max));
	for (int a, b, c, i = 0;i < M;i++)
	{
		std::cin >> a >> b >> c;
		road[a][b] = c;
	}

	for (int i = 0;i < N + 1;i++)
		road[i][i] = 0;

	for (int m = 1;m < N + 1;m++)
	{
		for (int s = 1;s < N + 1;s++)
		{
			for (int f = 1;f < N + 1;f++)
			{
				if(road[s][f]> road[s][m] + road[m][f])
					road[s][f] = road[s][m] + road[m][f];
			}
		}
	}


	int Min = 1000000000;
	for (int i = 1;i < N;i++)
	{
		for (int j = i+1;j < N + 1;j++)
		{
			int temp = road[i][j] + road[j][i];
			if (temp < Min)
				Min = temp;
		}
	}
	
	if (Min >= Max)
		std::cout << "-1";
	else
		std::cout << Min;

	return 0;
}