//뱀과 사다리 게임
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	vi map(101),check(101);

	for (int x,y,i = 0;i < N + M;i++)
	{
		std::cin >> x >> y;
		check[x] = -1;
		map[x] = y;
	}

	std::queue<int> Box;
	Box.push(1);
	int x;
	while (true)
	{
		x = Box.front();
		if (x > 93)
		{
			std::cout << check[x]+1;
			break;
		}

		for (int nx, i = 1;i < 7;i++)
		{
			nx = x + i;
			if (check[nx] == 0)
			{
				check[nx] = check[x] + 1;
				Box.push(nx);
			}
			else if (check[nx] == -1)
			{
				check[nx] = -2;
				if (check[map[nx]] == 0)
				{
					check[map[nx]] = check[x] + 1;
					Box.push(map[nx]);
				}
			}
		}

		Box.pop();
	}

	return 0;
}