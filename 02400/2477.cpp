//참외밭
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;


void Solve()
{
	int C;
	std::cin >> C;
	
	int tmp;
	vi edges(6);
	for (int i = 0; i < 6; i++)
		std::cin >> tmp >> edges[i];

	int start;
	for (int i = 0; i < 6; i++)
	{
		if (edges[i] == edges[(i + 2) % 6] + edges[(i + 4) % 6] && edges[(i + 1) % 6] == edges[(i + 3) % 6] + edges[(i + 5) % 6])
		{
			start = i;
			break;
		}
	}

	std::cout << C * (edges[start] * edges[(start + 1) % 6] - edges[(start + 3) % 6] * edges[(start + 4) % 6]);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}