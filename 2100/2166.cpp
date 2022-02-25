//다각형의 면적
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long double ld;
typedef std::pair<ld, ld> pl;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<pl> vpos(N);
	for (auto& [a, b] : vpos)
		std::cin >> a >> b;

	long double ans = (vpos.back().first + vpos.front().first) * (vpos.back().second -vpos.front().second);
	for (int i = 0;i < N - 1;i++)
	{
		ans += (vpos[i].first + vpos[i+1].first) * (vpos[i].second - vpos[i+1].second);
	}
	ans = (std::round(std::abs(ans) * 5) / 10);

	std::cout<<std::fixed;
	std::cout.precision(1);
	std::cout << ans;
	
	return 0;
}