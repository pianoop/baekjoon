//가장 가까운 공통 조상
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

void Solve()
{
	int N;
	std::cin >> N;

	int par, chd;
	vi edges(N + 1);
	for(int i=1;i<N;i++)
	{
		std::cin >> par >> chd;
		edges[chd] = par;
	}

	bool* bChecks = new bool[N + 1](false);
	int a, b;
	std::cin >> a >> b;
	while (a != 0)
	{
		bChecks[a] = true;
		a = edges[a];
	}

	while (true)
	{
		if (bChecks[b])
			break;

		bChecks[b] = true;
		b = edges[b];
	}
	std::cout << b << "\n";

	delete[] bChecks;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while(T--)
		Solve();

	return 0;
}