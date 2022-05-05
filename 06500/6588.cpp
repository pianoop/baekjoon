//골드바흐의 추측
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

void Solve()
{
	bool prep[1'000'001];
	std::memset(prep, true, sizeof(bool) * (1'000'001));

	prep[1] = false;
	for (int i = 2; i < 1001; i++)
	{
		if (prep[i])
		{
			for (int j = i << 1; j < 1'000'001; j += i)
				prep[j] = false;
		}
	}

	vi Prime;
	for (int i = 1; i < 1'000'001; i++)
	{
		if (prep[i])
			Prime.push_back(i);
	}

	int n;
	while (true)
	{
		std::cin >> n;
		if (n == 0)
			break;

		bool flag = false;
		int L = 0, l = 2; //Prime[0]
		while (l <= n / 2)
		{
			if (prep[n - l])
			{
				flag = true;
				break;
			}

			l = Prime[++L];
		}

		if (flag)
			std::cout << n << " = " << l << " + " << n - l << "\n";
		else
			std::cout << "Goldbach's conjecture is wrong.\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}