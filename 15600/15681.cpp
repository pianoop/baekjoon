//트리와 쿼리
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int solve(int now, int prev, vi& tree, const vvi& edges)
{
	if (int(edges[now].size()) == 1)
		return 1;

	for (auto& a : edges[now])
	{
		if (a != prev)
		{
			tree[now] += solve(a, now, tree, edges);
		}
	}
	return tree[now];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, R, Q;
	std::cin >> N >> R >> Q;

	vvi edges(N + 1);
	for (int i = 1;i < N;i++)
	{
		int a, b;
		std::cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vi tree(N + 1,1);
	for (auto& a : edges[R])
	{
		tree[R] += solve(a, R, tree, edges);
	}

	while(Q--)
	{
		int q;
		std::cin >> q;

		std::cout << tree[q] << "\n";
	}

	return 0;
}