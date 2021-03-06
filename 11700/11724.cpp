//연결 요소의 개수
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void BFS(int x,const vvi& C, vi& check)
{
	check[x] = 1;
	for (auto& a : C[x])
	{
		if (check[a] == 0)
			BFS(a, C, check);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	vvi connect(N + 1);
	for (int x, y, i = 0;i < M;i++)
	{
		std::cin >> x >> y;
		connect[x].push_back(y);
		connect[y].push_back(x);
	}
	vi check(N + 1);

	int ans = 0;
	for (int i = 1;i <= N;i++)
	{
		if (check[i] == 0)
		{
			ans++;
			BFS(i, connect, check);
		}
	}

	std::cout << ans;

	return 0;
}