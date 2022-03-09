//계단 수
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solve
{
public:
	Solve(int n) :N(n)
	{
		DP.resize(10, vvi(N, vi(1024, -1)));   //[10][N][1024]
		subDP.resize(N - 9, vi(10));         //[N-9][10]

		FillsubDP();

		for (int i = 1; i < 10; i++)
		{
			ans += FillDP(i, N - 1, 0);
			ans %= div;
		}
	}

	int FillDP(int now, int depth, int visitbit)
	{
		visitbit |= (1 << now);
		if (DP[now][depth][visitbit] != -1)
		{
			return DP[now][depth][visitbit];
		}
		if (visitbit == 1023)
		{
			DP[now][depth][visitbit] = subDP[depth][now];
			return DP[now][depth][visitbit];
		}
		if (depth == 0)
			return 0;

		DP[now][depth][visitbit] = 0;
		if (now != 9)
		{
			DP[now][depth][visitbit] += FillDP(now + 1, depth - 1, visitbit);
			DP[now][depth][visitbit] %= div;
		}
		if (now != 0)
		{
			DP[now][depth][visitbit] += FillDP(now - 1, depth - 1, visitbit);
			DP[now][depth][visitbit] %= div;
		}

		return DP[now][depth][visitbit];
	}

	void FillsubDP()
	{
		std::fill(subDP[0].begin(), subDP[0].end(), 1);

		for (int i = 1; i < int(subDP.size()); i++)
		{
			subDP[i][0] = subDP[i - 1][1];
			for (int j = 1; j < 9; j++)
			{
				subDP[i][j] = (subDP[i - 1][j - 1] + subDP[i - 1][j + 1]) % div;
			}
			subDP[i][9] = subDP[i - 1][8];
		}
	}

	void Printans()
	{
		printf("%d", ans);
	}

private:
	const int div = 1'000'000'000;
	int N;
	int ans = 0;
	std::vector<vvi> DP;
	vvi subDP;
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int N;
	std::cin >> N;
	if (N > 10)
	{
		Solve sol(N);
		sol.Printans();
	}
	else if (N == 10)
		printf("1");
	else
		printf("0");

	return 0;
}