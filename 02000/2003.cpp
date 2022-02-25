//수들의 합 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <array>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, x;
	std::cin >> N >> x;

	vi TP;
	TP.reserve(N);
	for (int x, i = 0;i < N;i++)
	{
		std::cin >> x;
		TP.push_back(x);
	}

	int total = TP.front(), cnt = 0;
	auto iters = TP.begin(), iterf = TP.begin();
	while (iterf!=TP.end())
	{
		if (total < x)
		{
			iterf++;
			if (iterf == TP.end())
				break;
			total += *iterf;
		}
		else if (total > x)
		{
			total -= *iters;
			iters++;
		}
		else
		{
			cnt++;
			total -= *iters;
			iters++;
		}
	}

	std::cout << cnt;

	return 0;
}