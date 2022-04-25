//나머지 합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

void Solve()
{
	int n, m;
	std::cin >> n >> m;

	int total = 0, tmp;
	vi remainder(m);
	while (n--)
	{
		std::cin >> tmp;
		total = (total + tmp) % m;
		remainder[total]++;
	}

	long long ans = remainder[0];
	for (int num : remainder)
		ans += (long long)num * (num - 1) / 2;  // nP2

	std::cout << ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();


	return 0;
}