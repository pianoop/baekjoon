//트리
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M, T=0;
	while (std::cin >> N >> M)
	{
		T++;
		if (N == 0)
			break;

		vvi tree(N + 1);
		for (int a,b,i = 0;i < M;i++)
		{
			std::cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}

		vi check(N + 1);
		int total = 0;
		for (int i = 1;i < N + 1;i++)
		{
			if (check[i] == 0)
			{
				check[i] = 1;
				bool flag = 1;
				std::queue<pi> Box;
				Box.push({ i,0 });
				while (!Box.empty())
				{



					for (auto& a : tree[Box.front().first])
					{
						if (check[a] == 0)
						{
							check[a] = 1;
							Box.push({ a , Box.front().first });
						}
						else if (a != Box.front().second)
							flag = 0;
					}
					Box.pop();
				}

				if (flag)
					total++;
			}
		}
		std::cout << "Case " << T << ": ";
		if (total == 0)
			std::cout << "No trees.\n";
		else if (total == 1)
			std::cout << "There is one tree.\n";
		else
			std::cout << "A forest of " << total << " trees.\n";
	}

	return 0;
}