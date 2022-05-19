//대칭 차집합
//-------------------------------------------------------------------
#include <iostream>
#include <cstring>


void Solve()
{
	int N, M;
	std::cin >> N >> M;

	bool* A = new bool[100'000'001];
	memset(A, false, sizeof(bool)* 100'000'001);

	int tmp;
	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp;
		A[tmp] = true;
	}

	int inter = 0;
	for (int i = 0; i < M; i++)
	{
		std::cin >> tmp;
		if (A[tmp])
			inter++;
	}

	std::cout << N + M - 2 * inter;
	delete[] A;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}