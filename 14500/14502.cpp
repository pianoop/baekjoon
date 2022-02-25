//연구소
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int nx[4] = { 0,0,1,-1 }, ny[4] = { 1,-1,0,0 };

bool checkin(const int& a, const int& b, const int& N, const int& M)
{
	return a > -1 && b > -1 && a < N&& b < M;
}

int countzero(const vvi& map)
{
	int n = 0;

	for (auto& a : map)
		for (auto& b : a)
			if (b == 0)
				n++;

	return n;
}

void DFS(const int& a, const int& b, const int& N, const int& M, vvi& cpymap)
{
	for (int nn, nm, i = 0;i < 4;i++)
	{
		nn = a + ny[i], nm = b + nx[i];
		if (checkin(nn, nm, N, M) && (cpymap[nn][nm] == 0 || cpymap[nn][nm] == 2))
		{
			cpymap[nn][nm] = 3;
			DFS(nn, nm, N, M, cpymap);
		}
	}
}

int infection(const int& N, const int& M, vvi cpymap)
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (cpymap[i][j] == 2)
			{
				cpymap[i][j] = 3;
				DFS(i, j, N, M, cpymap);
			}
		}
	}
	return countzero(cpymap);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	vvi map(N, vi(M, 0));
	for (auto& a : map)
		for (auto& b : a)
			std::cin >> b;

	int temp = N * M, Max = 0;
	for (int a1, a2, i = 0;i < temp;i++)
	{
		a1 = i / M, a2 = i % M;
		if (map[a1][a2] != 0)
			continue;

		map[a1][a2] = 1;
		for (int b1, b2, j = i + 1;j < temp;j++)
		{
			b1 = j / M, b2 = j % M;
			if (map[b1][b2] != 0)
				continue;

			map[b1][b2] = 1;
			for (int c1, c2, k = j + 1;k < temp;k++)
			{
				c1 = k / M, c2 = k % M;
				if (map[c1][c2] != 0)
					continue;

				map[c1][c2] = 1;

				int tmp = infection(N, M, map);
				if (Max < tmp)
					Max = tmp;

				map[c1][c2] = 0;
			}
			map[b1][b2] = 0;
		}

		map[a1][a2] = 0;
	}

	std::cout << Max;

	return 0;
}