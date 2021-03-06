//숨바꼭질3
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
int K, Max;

void BFS(vi& map, std::queue<int>& box)
{
	int x;
	while (!box.empty())
	{
		x = box.front();

		int nx = x + 1;
		if (nx < Max && nx > 0 && map[x]+1 < map[nx])
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		nx = x - 1;
		if (nx < Max && nx > 0 && map[x] + 1 < map[nx])
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		nx = x * 2;
		if (nx < Max && nx > 0 && map[x] < map[nx])
		{
			map[nx] = map[x];
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

	if (K <= N)
		std::cout << N - K;
	else 
	{
		Max = K * 2;
		vi map(Max, 200000);
		map[N] = 1;
		std::queue<int> box;
		box.push(N);
		BFS(map, box);
		std::cout << map[K] - 1;
	}

	return 0;
}