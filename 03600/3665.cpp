//최종 순위
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void Input(const int& N, vvi& edges, vi& indegree)
{
	vi lastyear(N);
	for (int i = 0;i < N;i++)
	{
		std::cin >> lastyear[i];
		indegree[lastyear[i]] = i;
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = i + 1;j < N;j++)
		{
			edges[lastyear[i]][lastyear[j]] = 1;
		}
	}

	int M;
	std::cin >> M;
	while (M--)
	{
		int a, b;
		std::cin >> a >> b;
		if (edges[a][b])
		{
			indegree[a]++;
			indegree[b]--;
			edges[a][b] = 0;
			edges[b][a] = 1;
		}
		else
		{
			indegree[a]--;
			indegree[b]++;
			edges[a][b] = 1;
			edges[b][a] = 0;
		}
	}
}

int Sort(const int& N, vvi& edges, vi& indegree, std::queue<int>& ans)
{
	std::queue<int> BFSbox;

	for (int i = 1;i <= N;i++)
	{
		if (indegree[i] == 0)
		{
			BFSbox.push(i);
			ans.push(i);
		}
	}

	while (!BFSbox.empty())
	{
		for (int under = 1;under <= N;under++)
		{
			if (edges[BFSbox.front()][under] && --indegree[under] == 0)
			{
				BFSbox.push(under);
				ans.push(under);
			}
		}

		BFSbox.pop();
	}

	if (int(ans.size()) != N)
		return 0;
	else
		return 1;
}

void Print(const int& res, std::queue<int>& ans)
{
	if (res == 1)
	{
		while (!ans.empty())
		{
			printf("%d ", ans.front());
			ans.pop();
		}
	}
	else
	{
		printf("IMPOSSIBLE");
	}
	printf("\n");
}

void Solve()
{
	int N;
	std::cin >> N;
	vvi edges(N + 1, vi(N + 1));
	vi indegree(N + 1);
	Input(N, edges, indegree);

	int res;
	std::queue<int> ans;
	res = Sort(N, edges, indegree, ans);
	Print(res, ans);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		Solve();
	}

	return 0;
}