//숨바꼭질 4
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
typedef std::vector<int> vi;
int K, Max;

void BFS(vi& map, std::queue<int>& box)
{
	int x;
	while (!box.empty())
	{
		x = box.front();
		if (x == K)
			return;

		int nx = x + 1;
		if (nx < Max && nx >= 0 && map[nx] == 0)
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		nx = x - 1;
		if (nx < Max && nx >= 0 && map[nx] == 0)
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		nx = x * 2;
		if (nx < Max && nx >= 0 && map[nx] == 0)
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}

		box.pop();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N >> K;

	if (K - N <= 0)
	{
		std::cout << N - K<<"\n";
		while (N != K)
		{
			std::cout << N<<" ";
			N--;
		}
		std::cout << K;
	}
	else
	{
		Max = K * 2;
		vi map(Max);
		map[N] = 1;
		std::queue<int> box;
		box.push(N);
		BFS(map, box);
		std::cout << map[K] - 1 << "\n";

		std::stack<int> ans;
		int x = K;
		while (true)
		{
			ans.push(x);
			if (map[x] == 1)
				break;

			if (x > 0 && map[x - 1] == map[x] - 1)
				x = x - 1;
			else if (map[x + 1] == map[x] - 1)
				x = x + 1;
			else
				x /= 2;
		}

		while (!ans.empty())
		{
			std::cout << ans.top() << " ";
			ans.pop();
		}
	}

	return 0;
}