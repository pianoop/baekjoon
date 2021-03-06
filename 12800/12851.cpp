//숨바꼭질 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
int K, Max;

int BFS(vi& map, std::queue<int>& box)
{
	int x, ans=100001;
	bool flag = 0;
	while (!box.empty())
	{
		x = box.front();
		if (x == K)
		{
			if (flag)
			{
				ans++;
			}
			else
			{
				flag = 1;
				ans = 1;
			}
		}
		if (flag && map[x] > map[K])
			break;

		int nx = x + 1;
		if (nx < Max && nx > 0 && map[x]+1 <= map[nx])
		{
			if (nx == K)
			{

			}
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		nx = x - 1;
		if (nx < Max && nx > 0 && map[x] + 1 <= map[nx])
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		nx = x * 2;
		if (nx < Max && nx > 0 && map[x] + 1 <= map[nx])
		{
			map[nx] = map[x] + 1;
			box.push(nx);
		}
		
		box.pop();
	}

	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N >> K;

	if (K <= N)
		std::cout << N - K<< "\n1";
	else 
	{
		int ans;
		Max = K * 2;
		vi map(Max, 200000);
		map[N] = 1;
		std::queue<int> box;
		box.push(N);
		ans=BFS(map, box);
		std::cout << map[K] - 1<<"\n"<<ans;
	}

	return 0;
}