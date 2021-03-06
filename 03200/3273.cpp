//두 수의 합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vi TP;
	TP.reserve(N);
	for (int x, i = 0;i < N;i++)
	{
		std::cin >> x;
		TP.push_back(x);
	}

	int x, cnt = 0;
	std::cin >> x;

	std::sort(TP.begin(), TP.end());
	auto iters = TP.begin(), iterf = (--TP.end());

	while (iterf != iters)
	{
		if (*iters + *iterf < x)
			iters++;
		else if (*iters + *iterf > x)
			iterf--;
		else
		{
			cnt++;
			iterf--;
		}
	}

	std::cout << cnt;

	return 0;
}