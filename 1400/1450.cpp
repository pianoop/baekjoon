//냅색문제
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int pow1(const int& a, const int& b)
{
	int ans = 1;
	for (int i = 0;i < b;i++)
		ans *= a;

	return ans;
}

void SumCalc(int S, int n, const vi& bag, const int& N, vi& sums, const int& Sum)
{
	if (n == N)
	{
		sums.push_back(S);
		return;
	}
	if (S > Sum)
		return;

	SumCalc(S + bag[n + 1], n + 1, bag, N,sums,Sum);
	SumCalc(S, n + 1, bag, N,sums,Sum);
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, Sum;
	long long ans = 0;
	std::cin >> N >> Sum;
	vi bag(N);
	for (int i = 0;i < N;i++)
	{
		std::cin >> bag[i];
	}

	vi sums1, sums2;
	sums1.reserve(pow1(2, N / 2));
	sums2.reserve(pow1(2, N / 2 + 1));
	SumCalc(0, -1, bag, N / 2 - 1,sums1, Sum);
	SumCalc(0, N / 2 - 1, bag, N - 1, sums2,Sum);

	std::sort(sums2.begin(), sums2.end());

	for (auto& a : sums1)
	{
		ans += std::upper_bound(sums2.begin(), sums2.end(), Sum - a) - sums2.begin();
	}

	std::cout << ans;

	return 0;
}