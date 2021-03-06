//거짓말
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int FindRoot(const int& a, vi& table)
{
	if (table[a] == table[table[a]])
		return table[a];

	return table[a] = FindRoot(table[a], table);
}

void merge(int a, int b, vi& table)
{
	a = FindRoot(a, table);
	b = FindRoot(b, table);
	if (a != b)
		table[b] = a;
}

bool Djoint(int a, int b, vi& table)
{
	a = FindRoot(a, table);
	b = FindRoot(b, table);
	if (a == b)
		return 1;

	return 0;;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m, T;
	std::cin >> n >> m >> T;

	if (T > 0)
	{
		vi people(n + 1);
		for (int i = 1;i < n + 1;i++)
			people[i] = i;

		int knownroot;
		std::cin >> knownroot;
		for (int tmp,i = 1;i < T;i++)
		{
			std::cin >> tmp;
			merge(knownroot, tmp, people);
		}

		int ans = 0;
		vi firsts;
		firsts.reserve(m);
		for (int first, x, i = 0;i < m;i++)
		{
			std::cin >> x >> first;
			firsts.push_back(first);
			for (int tmp, j = 1;j < x;j++)
			{
				std::cin >> tmp;
				merge(first, tmp, people);
			}
		}

		for (int i = 0;i < m;i++)
		{
			if (!Djoint(knownroot, firsts[i], people))
				ans++;
		}
		std::cout << ans;
	}
	else
		std::cout << m;
	return 0;
}