//경찰서
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


class SCC
{
public:
	SCC()
	{
		input();
		calc();
	}

	void PrintAns()
	{
		std::cout << mTotal;
	}

private:
	void input()
	{
		int n;
		std::cin >> n;
		graph.resize(n);
		cost.resize(n);

		for (auto& c : cost)
			std::cin >> c;

		char tmp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cin >> tmp;
				if (tmp == 49)
					graph[i].push_back(j);
			}
		}
				
	}

	void calc()
	{
		int v = int(graph.size());
		std::stack<int> stack;
		vi discover(v, -1);
		int cnt = 0;
		bool* bFin = new bool[v];
		memset(bFin, false, sizeof(bool) * (v));

		for (int i = 0; i < v; i++)
		{
			if (discover[i] == -1)
				dfs(i, stack, discover, cnt, bFin);
		}

		delete[] bFin;
	}

	int dfs(int now, std::stack<int>& stack, vi& discover, int& cnt, bool* fin)
	{
		stack.push(now);
		int parent = discover[now] = cnt++;

		for (const auto& next : graph[now])
		{
			if (discover[next] == -1)
				parent = std::min(parent, dfs(next, stack, discover, cnt, fin));
			else if (!fin[next])
				parent = std::min(parent, discover[next]);
		}

		if (parent == discover[now])
		{
			int min = 1'000'001;

			while (true)
			{
				fin[stack.top()] = true;

				min = std::min(min, cost[stack.top()]);

				if (stack.top() == now)
				{
					stack.pop();
					break;
				}
				stack.pop();
			}

			mTotal += min;
		}

		return parent;
	}

private:
	vvi graph;
	vi cost;
	int mTotal = 0;
};

void Solve()
{
	SCC scc;
	scc.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}