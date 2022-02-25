//부분수열의 합2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <array>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

std::array<int, 4000001> sums;
const int MAX = (int)4e6;
const int halfM = (int)2e6;
long long ans = 0;

void SumCalc1(int S, int n, const vi& bag, const int& N)
{
	if (n == N)
	{
		sums[S + halfM]++;
		return;
	}

	SumCalc1(S + bag[n + 1], n + 1, bag, N);
	SumCalc1(S, n + 1, bag, N);
}

void SumCalc2(int S, int n, const vi& bag, const int& N, const int& Sum)
{
	if (n == N)
	{
		if (Sum - S < 0 || Sum - S > MAX)
			return;
		ans += sums[Sum - S];
		return;
	}

	SumCalc2(S + bag[n + 1], n + 1, bag, N, Sum);
	SumCalc2(S, n + 1, bag, N, Sum);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, Sum;
	std::cin >> N >> Sum;
	if (Sum == 0)
		ans--;
	vi bag(N);
	for (int i = 0;i < N;i++)
	{
		std::cin >> bag[i];
	}

	SumCalc1(0, -1, bag, N / 2 - 1);
	Sum += halfM;
	SumCalc2(0, N / 2 - 1, bag, N - 1, Sum);

	std::cout << ans;

	return 0;
}