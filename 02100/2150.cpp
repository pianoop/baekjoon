//Strongly Connected Component
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
		std::cout << scc.size() << "\n";
		for (auto& a : scc)
		{
			for (auto& b : a)
				std::cout << b << " ";
			std::cout << "-1 \n";
		}
	}

private:
	void input()
	{
		int v, e;
		std::cin >> v >> e;
		graph.resize(v + 1);
		scc.reserve(v);

		int a, b;
		while (e--)
		{
			std::cin >> a >> b;
			graph[a].push_back(b);
		}
	}

	void calc()
	{
		int v = int(graph.size()) - 1;
		std::stack<int> stack;
		vi discover(v + 1, -1);
		int cnt = 0;
		bool* bFin = new bool[v + 1];
		memset(bFin, false, sizeof(bool) * (v + 1));

		for (int i = 1; i <= v; i++)
		{
			if (discover[i] == -1)
				dfs(i, stack, discover, cnt, bFin);
		}

		std::sort(scc.begin(), scc.end(), [](vi& a, vi& b)->bool
			{
				return a[0] < b[0];
			});


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
			vi tmp;
			while (true)
			{
				fin[stack.top()] = true;
				tmp.push_back(stack.top());
				if (stack.top() == now)
				{
					stack.pop();
					break;
				}
				stack.pop();
			}
			std::sort(tmp.begin(), tmp.end());
			scc.push_back(tmp);
		}

		return parent;
	}

private:
	vvi scc, graph;
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