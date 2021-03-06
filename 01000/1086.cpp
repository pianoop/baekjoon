//박성원
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;
typedef std::vector<std::vector<ll> > vvl;

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::string> vs(N+1);
	vi length(N+1);
	ll all=1;
	for (int i = 1;i <= N;i++)
	{
		all *= i;
		std::cin >> vs[i];
		length[i] = vs[i].length();
	}

	int K;
	std::cin >> K;

	vi remain(N+1);
	for (int i = 1;i <= N;i++)
	{
		int temp = 0;
		for (int j = 0;j < length[i];j++)
		{
			temp *= 10;
			temp += (vs[i][j] - 48);
			temp %= K;
		}
		remain[i] = temp;
	}

	vvi underK(K, vi(51));
	for (int i = 1;i < K;i++)
	{
		underK[i][0] = i;
		for (int j = 1;j < 51;j++)
		{
			underK[i][j] = (underK[i][j - 1] * 10) % K;
		}
	}

	int end = 1 << N;
	vvl answer(end, std::vector<ll>(K));
	answer[0][0] = 1;
	for (int i = 1;i < end;i++)
	{
		for (int tmp = 0, j = 1;j <= N; j++, tmp++)
		{
			if (i & (1 << tmp))
			{
				for (int k = 0;k < K;k++)
				{
					answer[i][(underK[k][length[j]]+remain[j])%K] += answer[i - (1 << tmp)][k];
				}
			}
		}
	}

	ll& ans = answer[end - 1][0];

	if (ans == 0)
		std::cout << "0/1";
	else
	{
		ll tmp = gcd(ans, all);
		ans /= tmp, all /= tmp;

		std::cout << ans << "/" << all;
	}

	return 0;
}