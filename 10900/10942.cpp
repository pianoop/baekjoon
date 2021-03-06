//팰린드롬?
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;
	vi nums(N + 1);

	for (int i = 1;i <= N;i++)
		std::cin >> nums[i];

	vvb DP(N + 1, vb(N + 1, 1));

	for (int i = 1;i < N;i++)
	{
		int a = 1;
		int n = N - i;
		while (n--)
		{
			int b = a + i;

			if (DP[a + 1][b - 1] && nums[a] == nums[b])
				DP[a][b] = true;
			else
				DP[a][b] = false;
			a++;
		}
	}

	int T, a, b;
	std::cin >> T;
	while (T--)
	{
		std::cin >> a >> b;
		std::cout << DP[a][b] << "\n";
	}

	return 0;
}