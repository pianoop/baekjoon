//친구 네트워크
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <unordered_map>
typedef std::vector<std::pair<int, int> > vpi;
typedef std::vector<vpi> vvi;

int FindRoot(const int& a, vpi& table)
{
	if (table[a].first == table[table[a].first].first)
		return table[a].first;

	table[a].first = FindRoot(table[a].first, table);
	return table[a].first;
}

int merge(int a, int b, vpi& table)
{
	a = FindRoot(a, table);
	b = FindRoot(b, table);
	if (a == b)
		return table[a].second;

	table[b].first = a;
	table[a].second += table[b].second;
	return table[a].second;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		int F;
		std::cin >> F;
		std::unordered_map<std::string, int> Fmap;
		vpi Fnet;
		Fnet.reserve(F * 2);

		std::string s1, s2;
		while (F--)
		{
			std::cin >> s1 >> s2;
			if (Fmap.insert({ s1,Fmap.size() }).second)
				Fnet.push_back({ Fmap.size() - 1, 1 });
			if (Fmap.insert({ s2,Fmap.size() }).second)
				Fnet.push_back({ Fmap.size() - 1, 1 });

			std::cout << merge(Fmap[s1], Fmap[s2], Fnet) << "\n";
		}
	}

	return 0;
}