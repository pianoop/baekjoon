//사회망 서비스(SNS)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int DFS(const int now, const int prev,  int& ans, const vvi& edges)
{
	if (now != 1 && int(edges[now].size()) == 1)
		return 0;
	
	int flag = 1;

	for (auto& a : edges[now])
	{
		if (a != prev)
			flag*= DFS(a, now, ans, edges);
	}

	if (flag == 0)
	{
		ans++;
		return 1;
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vvi edges(N + 1);
	for (int i = 1;i < N;i++)
	{
		int a, b;
		std::cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int ans = 0;

	DFS(1, 0, ans, edges);
	
	std::cout << ans;

	return 0;
}