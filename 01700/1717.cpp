//집합의 표현
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
	for (int i = 0;i < n + 1;i++)
		set[i] = i;

	for (int a,b,c,i = 0;i < m;i++)
	{
		std::cin >> a >> b >> c;

		if (a == 0)
			merge(b, c, set);
		else if (DUnion(b, c, set))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

	return 0;
}