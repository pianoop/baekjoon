//팰린드롬 분할
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<int> vi;

void Input(vvb& palin)
{
	std::string s;
	std::cin >> s;

	int n = s.length();
	palin.resize(n, vb(n));
	palin[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		palin[i][i] = 1;
		if (s[i - 1] == s[i])
			palin[i - 1][i] = 1;
	}

	for (int l = 2; l < n; l++)
	{
		for (int i = 0; i < n - l; i++)
		{
			if (s[i] == s[i + l] && palin[i + 1][i + l - 1])
			{
				palin[i][i + l] = 1;
			}
		}
	}
}

int DP(vvb& palin)
{
	int n = int(palin.size());
	vi DP(n + 1, -1);
	DP[0] = 0;
	DP[1] = 1;

	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= j; i++)
		{
			if (palin[i - 1][j - 1])
			{
				if (DP[j] == -1 || DP[i - 1] + 1 < DP[j])
					DP[j] = DP[i - 1] + 1;
			}
		}
	}

	return DP[n];
}

void Solve()
{
	vvb palin;
	Input(palin);
	printf("%d", DP(palin));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}