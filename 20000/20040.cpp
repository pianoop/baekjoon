//사이클 게임
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvpi;

int FindRoot(const int& a, vi& table)
{
	if (table[a] == table[table[a]])
		return table[a];

	table[a] = FindRoot(table[a], table);
	return table[a];
}

bool merge(int a, int b, vi& table)
{
	a = FindRoot(a, table);
	b = FindRoot(b, table);
	if (a == b)
		return 1;

	table[b] = a;
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	vi graph;
	graph.reserve(n);
	for (int i = 0;i < n;i++)
		graph.push_back(i);
	
	bool flag = 0;
	int ans;
	for (int a,b,i = 1;i < m + 1;i++)
	{
		std::cin >> a >> b;
		if (merge(a, b, graph))
		{
			flag = 1;
			ans = i;
			break;
		}
	}

	if (flag)
		std::cout << ans;
	else
		std::cout << "0";

	return 0;
}