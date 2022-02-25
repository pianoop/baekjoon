//플로이드 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int Max = 100000001;
	int N, M;
	std::cin >> N >> M;

	vvi bus(N + 1, vi(N + 1, Max));
	std::vector<std::vector<std::pair<int,int> > > inbus(N + 1);
	for (int a, b, c, i = 0;i < M;i++)
	{
		std::cin >> a >> b >> c;
		if (bus[a][b] > c)
		{
			bus[a][b] = c;
			inbus[b].push_back({ a, c });
		}
	}

	for (int i = 1;i < N + 1;i++)
		bus[i][i] = 0;

	for (int m = 1;m < N + 1;m++)
	{
		for (int s = 1;s < N + 1;s++)
		{
			for (int f = 1;f < N + 1;f++)
			{
				if(bus[s][f]> bus[s][m] + bus[m][f])
					bus[s][f] = bus[s][m] + bus[m][f];
			}
		}
	}

	for (int i = 1;i < N + 1;i++)
	{
		for (int j = 1;j < N + 1;j++)
		{
			if (bus[i][j] == Max)
				std::cout << "0 ";
			else
				std::cout << bus[i][j] << " ";
		}
		std::cout << "\n";
	}

	for (int i = 1;i < N + 1;i++)
	{
		for (int j = 1;j < N + 1;j++)
		{
			if (bus[i][j] == Max || i==j)
				std::cout << "0 ";
			else
			{
				int f = j, dist = bus[i][j];
				std::stack<int> ans;
				ans.push(f);
				while (f!=i)
				{
					for (auto& [a, b] : inbus[f])
					{
						if (bus[i][a] + b == dist)
						{
							ans.push(a);
							f = a;
							dist -= b;
							break;
						}
					}
				}
				std::cout << int(ans.size()) << " ";
				while (!ans.empty())
				{
					std::cout << ans.top() << " ";
					ans.pop();
				}
			}
			std::cout << "\n";
		}
	}

	return 0;
}