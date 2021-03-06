//트리의 지름
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<std::vector<std::pair<int, int> > > vvp;

void DFS(int now, int uplen, const vvp& tree, vi& check, vi& ans)
{
	int Max = 0;
	for (auto& [to, len] : tree[now])
	{
		if (check[to] == 0)
		{
			check[to] = 1;
			DFS(to, len,tree, check, ans);
			if (ans[to] > Max)
				Max = ans[to];
		}
	}
	ans[now] = Max + uplen;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N;
	std::cin >> N;

	vvp treebox(N + 1);
	for (int a, b, c, i = 0;i < N;i++)
	{
		std::cin >> a;
		while (true)
		{
			std::cin >> b;
			if (b == -1)
				break;
			std::cin >> c;
			treebox[a].push_back({ b,c });
		}
	}

	vi check(N + 1), ans(N + 1);
	check[1] = 1;
	DFS(1, 0, treebox, check, ans);

	vi(N + 1).swap(check);
	check[1] = 1;
	int Max = ans[1],Max1,Max2, x;
	std::queue<int> Box;
	Box.push(1);
	while (!Box.empty())
	{
		x = Box.front();
		Box.pop();
		Max1 = Max2 = 0;
		for (auto& [a, b] : treebox[x])
		{
			if (check[a] == 0)
			{
				check[a] = 1;
				Box.push(a);
				if (ans[a] >= Max1)
				{
					Max2 = Max1;
					Max1 = ans[a];
				}
				else if (ans[a] > Max2)
					Max2 = ans[a];
			}
		}
		if (Max < Max1 + Max2)
			Max = Max1 + Max2;
	}

	std::cout << Max;

	return 0;
}