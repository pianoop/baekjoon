//파일 합치기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#define INT_MAX 2147483647
typedef std::vector<int> vi;

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{

		int N;
		std::cin >> N;

		std::vector<vi> Matrixes(N,vi(N));
		for (int i = 0;i < N;i++)
		{
			std::cin >> Matrixes[i][i];
		}
		for (int i = 1;i < N;i++)
		{
			int a = 0;
			int n = N - i;
			while (n--)
			{
				int b = a + i;
				Matrixes[a][b] = Matrixes[a][b - 1] + Matrixes[b][b];
				a++;
			}
		}

		std::vector<vi> DP(N, vi(N, INT_MAX));
		for (int i = 0;i < N;i++)
			DP[i][i] = 0;

		for (int i = 1;i < N;i++)
		{
			int a = 0;
			int n = N - i;
			while (n--)
			{
				int b = a + i;
				int k = a;
				while (k < b)
				{
					DP[a][b] = Min(DP[a][b], DP[a][k] + DP[k + 1][b] + Matrixes[a][b]);
					k++;
				}
				a++;
			}
		}
		
		std::cout << DP[0][N - 1]<<"\n";
	}

	return 0;
}
