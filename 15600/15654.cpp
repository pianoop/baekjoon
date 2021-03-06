//N과 M(5)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void back(vi box, const int& N, const int& M, const vi& table, vi& check)
{
	if (int(box.size()) == M)
	{
		for (auto& a : box)
			std::cout << a << " ";
		std::cout << "\n";
		return;
	}

	for (int i=0;i<int(table.size());i++)
	{
		if (check[i] == 0)
		{
			check[i] = 1;
			box.push_back(table[i]);
			back(box, N, M, table, check);
			check[i] = 0;
			box.pop_back();
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	vi table(N);
	for (auto& a : table)
		std::cin >> a;

	std::sort(table.begin(), table.end());
	vi box,check(N);
	back(box, N, M, table,check);

	return 0;
}