//양팔저울
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

int N;

int abs1(const int& a)
{
	return a < 0 ? -a : a;
}

void solve(int curnums, int curweights, const vi& w, std::vector<vi>& dp)
{
	if (dp[curnums][curweights]==1)
		return;

	dp[curnums][curweights] = 1;

	if (curnums == N)
		return;

	solve(curnums + 1, curweights, w, dp);
	solve(curnums + 1, curweights + w[curnums], w, dp);
	solve(curnums + 1, abs1(curweights - w[curnums]), w, dp);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int total=0;
	std::cin >> N;
	vi weights;
	weights.reserve(N);
	for (int x, i = 0;i < N;i++)
	{
		std::cin >> x;
		weights.push_back(x);
		total += x;
	}

	std::vector<vi> DP(N+1,vi(total+1, 0));
	solve(0, 0, weights, DP);
	
	char ans[2] = { 'N','Y' };
	int T, x;
	std::cin >> T;
	while (T--)
	{
		std::cin >> x;
		if (x > total)
			std::cout << ans[0];
		else if(DP[N][x]==1)
			std::cout << ans[1];
		else
			std::cout << ans[0];
		std::cout << " ";
	}

	return 0;
}