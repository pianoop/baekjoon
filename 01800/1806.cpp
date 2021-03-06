//부분합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, S;
	std::cin >> N >> S;

	vi TP;
	TP.reserve(N);
	for (int x, i = 0;i < N;i++)
	{
		std::cin >> x;
		TP.push_back(x);
		if (x >= S)
		{
			std::cout << "1";
			return 0;
		}
	}

	auto iters = TP.begin(), iterf = TP.begin();
	int Min = 100001, total=TP.front(), size = 1;
	while (iterf != TP.end())
	{
		if (total < S)
		{
			iterf++;
			if (iterf == TP.end())
				break;
			total += *iterf;
			size++;
		}
		else
		{
			if (Min > size)
				Min = size;
			size--;
			total -= *iters;
			iters++;
		}
	}

	if (Min == 100001)
		std::cout << "0";
	else
		std::cout << Min;

	return 0;
}