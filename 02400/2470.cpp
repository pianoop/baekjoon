//두 용액
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int abs1(const int& a)
{
	return a > 0 ? a : -a;
}

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

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

	std::sort(TP.begin(), TP.end());
	auto iters = TP.begin(), iterf = (--TP.end());
	int ans = 0x7FFFFFFF, a=0,b=0;
	while (iters != iterf)
	{
		int temp = *iters + *iterf;
		if (abs1(temp) < ans)
		{
			ans = abs1(temp);
			a = *iters;
			b = *iterf;
		}

		if (temp < 0)
			iters++;
		else if (temp > 0)
			iterf--;
		else
		{
			a = *iters;
			b = *iterf;
			break;
		}
	}

	std::cout << a << " " << b;

	return 0;
}