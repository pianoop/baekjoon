//소수의 연속합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

bool bPrimeN[4000001];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;
	if (N == 1)
		std::cout << "0";
	else
	{
		bPrimeN[1] = 1;
		for (int i = 2;i * i <= N;i++)
		{
			if (bPrimeN[i] == 0)
			{
				for (int j = i * 2;j <= N;j += i)
				{
					bPrimeN[j] = 1;
				}
			}
		}

		vi PN;
		for (int i = 2;i <= N;i++)
		{
			if (bPrimeN[i] == 0)
				PN.push_back(i);
		}

		int total = PN.front(), cnt=0;
		auto iters = PN.begin(), iterf = PN.begin();
		while (true)
		{
			if (total > N)
			{
				total -= *iters;
				iters++;
			}
			else if (total < N)
			{
				iterf++;
				if (iterf == PN.end())
					break;
				total += *iterf;
			}
			else
			{
				cnt++;
				total -= *iters;
				iters++;
			}
		}
		std::cout << cnt;
	}
	return 0;
}