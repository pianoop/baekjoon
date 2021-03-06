//키 순서
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void DFS(const int& s, int m, vi& check, vi& ans, const vvi& path, const int& i)
{
	if (check[m] == i)
		return;

	check[m] = i;
	ans[s]++;
	ans[m]++;

	for (auto& a : path[m])
	{
		DFS(s, a, check, ans, path, i);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	vvi path(N + 1);
	for (int a, b, i = 0;i < M;i++)
	{
		std::cin >> a >> b;
		path[a].push_back(b);
	}

	vi ans(N + 1), check(N+1);
	for (int i = 1;i < N + 1;i++)
	{
		DFS(i, i, check, ans, path, i);
	}

	N++;
	int total = 0;
	for (int i = 1;i < N;i++)
	{
		if (ans[i] == N)
			total++;
	}

	std::cout << total;

	return 0;
}