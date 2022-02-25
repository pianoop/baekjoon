//구간 합 구하기4
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	
	vi nums(N+1);
	for (int i = 1;i <= N;i++)
	{
		std::cin >> nums[i];
		nums[i] += nums[i - 1];
	}
	int x, y;
	while (M--)
	{
		std::cin >> x >> y;
		std::cout << (nums[y] - nums[x - 1]) << "\n";
	}

	return 0;
}