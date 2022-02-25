//이분 그래프
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{

		int V, E;
		std::cin >> V >> E;
		vvi map(V + 1);
		for (int a, b, i = 0;i < E;i++)
		{
			std::cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		vi checknum(V + 1);
		std::queue<int> box;
		int x;
		bool flag = 0;
		for (int i = 1;i <= V;i++)
		{
			if (checknum[i] == 0)
			{
				checknum[i] = 1;
				box.push(i);

				while (!box.empty())
				{
					x = box.front();
					int c = checknum[x];
					for (auto& a : map[x])
					{
						if (checknum[a] == 0)
						{
							if (c == 1)
								checknum[a] = 2;
							else
								checknum[a] = 1;
							box.push(a);
						}
						else if (checknum[a] == c)
						{
							flag = 1;
							break;
						}
					}
					if (flag)
						break;

					box.pop();
				}
				if (flag)
					break;
			}
		}

		if (flag)
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}

	return 0;
}