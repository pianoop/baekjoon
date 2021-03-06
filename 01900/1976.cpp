//여행 가자
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int FindRoot(const int& a, vi& table)
{
	if (table[a] == table[table[a]])
		return table[a];

	table[a] = FindRoot(table[a], table);
	return table[a];
}

void merge(int a, int b, vi& table)
{
	a = FindRoot(a, table);
	b = FindRoot(b, table);
	if (a == b)
		return;

	table[b] = a;
}

bool DUnion(int a, int b, vi& table)
{
	a = FindRoot(a, table);
	b = FindRoot(b, table);
	if (a == b)
		return 1;
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	vi set(n + 1);
	for (int i = 1;i < n + 1;i++)
		set[i] = i;

	for (int i = 1;i < n + 1;i++)
	{
		for (int x,j = 1;j < n + 1;j++)
		{
			std::cin >> x;
			if (x == 1)
				merge(i, j,set);
		}
	}

	int root;
	std::cin >> root;
	bool D = 1;
	root = FindRoot(root, set);

	for (int x, i = 1;i < m;i++)
	{
		std::cin >> x;
		if (root != FindRoot(x, set))
		{
			D = 0;
			break;
		}
	}

	if (D)
		std::cout << "YES";
	else
		std::cout << "NO";

	return 0;
}