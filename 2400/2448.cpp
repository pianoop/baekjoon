//별 찍기 - 11
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;
typedef std::vector<std::vector<char> > vvc;

void staring(const int& a, const int& b, vvc& stars)
{
	stars[a][b] = '*';
	stars[a + 1][b - 1] = '*';
	stars[a + 1][b + 1] = '*';
	stars[a + 2][b] = '*';
	stars[a + 2][b - 1] = '*';
	stars[a + 2][b - 2] = '*';
	stars[a + 2][b + 1] = '*';
	stars[a + 2][b + 2] = '*';
}

void recursion(const int a, const int b, int N, vvc& stars)
{
	if (N == 1)
	{
		staring(a, b, stars);
	}
	else
	{
		recursion(a, b, N / 2, stars);
		recursion(a + N, b - N, N / 2, stars);
		recursion(a + N, b + N, N / 2, stars);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;
	vvc stars(N, std::vector<char>(N * 2, ' '));
	recursion(0, N-1, N / 2, stars);

	for (auto& a : stars)
	{
		for (auto& b : a)
			std::cout << b;
		std::cout << "\n";
	}

	return 0;
}