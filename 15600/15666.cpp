//N과 M (12)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

void solve(int n, int i,const int& N, const int& M, const vi& sequence, vi& ans)
{
	if (n == M)
	{
		for (auto& num : ans)
			std::cout << num << " ";
		std::cout << "\n";
		return;
	}

	int prev = 0;
	for (;i < N;i++)
	{
		if (prev == sequence[i])
			continue;
		prev = sequence[i];

		ans[n] = prev;
		solve(n + 1,i, N, M, sequence, ans);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	vi sequence(N);
	for (auto& a : sequence)
		std::cin >> a;

	std::sort(sequence.begin(), sequence.end());
	vi  ans(M);
	solve(0, 0, N, M, sequence, ans);

	return 0;
}