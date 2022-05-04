//약수의 합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;

void Solve()
{
	vi prep(1000001);
	vl ans(1000001);
	ll total = 0;
	int i = 1;

	for (; i <= 500000; i++)
	{
		for (int j = i; j <= 1000000; j += i)
			prep[j] += i;
	}

	for (i = 1; i <= 500000; i++)
		ans[i] = ans[i - 1] + prep[i];
	for (; i <= 1000000; i++)
		ans[i] = i + ans[i-1] +prep[i];

	int T, ask;
	std::cin >> T;
	while (T--)
	{
		std::cin >> ask;
		std::cout << ans[ask] << "\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}