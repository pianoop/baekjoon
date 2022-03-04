//문제집
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void Input(const int& N, vvi& edges, vi& indegree)
{
	int M;
	std::cin >> M;

	while (M--)
	{
		int a, b;
		std::cin >> a >> b;
		indegree[b]++;
		edges[a].push_back(b);
	}
}

void Sort(const int& N, vvi& edges, vi& indegree, std::queue<int>& ans)
{
	std::priority_queue<int,vi,std::greater<>> BFSbox;

	for (int i = 1;i <= N;i++)
	{
		if (indegree[i] == 0)
		{
			BFSbox.push(i);
		}
	}

	while (!BFSbox.empty())
	{
		int now = BFSbox.top();
		BFSbox.pop();

		ans.push(now);
		for (auto& under: edges[now])
		{
			if (--indegree[under] == 0)
			{
				BFSbox.push(under);
			}
		}
	}
}

void Print(std::queue<int>& ans)
{
	while (!ans.empty())
	{
		printf("%d ", ans.front());
		ans.pop();
	}
}

void Solve()
{
	int N;
	std::cin >> N;
	vi indegree(N+1);
	vvi edges(N+1);
	std::queue<int> ans;
	Input(N, edges, indegree);
	Sort(N, edges, indegree, ans);
	Print(ans);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}