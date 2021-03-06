//1로 만들기 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vi check(N + 1);
	std::queue<int> Box;
	Box.push(N);
	check[N] = 1;
	int x, temp;
	while (true)
	{
		x = Box.front();
		Box.pop();
		if (x == 1)
			break;

		if (x % 3 == 0)
		{
			temp = x / 3;
			if (check[temp] == 0)
			{
				Box.push(temp);
				check[temp] = check[x] + 1;
			}
		}
		if (x % 2 == 0)
		{
			temp = x / 2;
			if (check[temp] == 0)
			{
				Box.push(temp);
				check[temp] = check[x] + 1;
			}
		}
		if (check[x - 1] == 0)
		{
			check[x - 1] = check[x] + 1;
			Box.push(x - 1);
		}
	}

	std::cout << check[1]-1 << "\n";

	std::stack<int> ans;
	x = 1;
	while (x != N)
	{
		ans.push(x);

		if (check[x + 1] == check[x] - 1)
			x++;
		else if (check[x * 2] == check[x] - 1)
			x *= 2;
		else
			x *= 3;
	}

	std::cout << N << " ";
	while (!ans.empty())
	{
		std::cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}