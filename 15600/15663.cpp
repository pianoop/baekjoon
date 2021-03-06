//N과 M (9)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

void solve(int n, const int& N, const int& M, const vi& sequence, vi& check, vi& ans)
{
	if (n == M)
	{
		for (auto& num : ans)
			std::cout << num << " ";
		std::cout << "\n";
		return;
	}

	int prev = 0;
	for (int i = 0;i < N;i++)
	{
		if (check[i] == 0)
		{
			if (prev == sequence[i])
				continue;
			prev = sequence[i];

			check[i] = 1;
			ans[n] = prev;
			solve(n + 1, N, M, sequence, check, ans);
			check[i] = 0;
		}
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
	vi check(N), ans(M);
	solve(0, N, M, sequence, check, ans);

	return 0;
}