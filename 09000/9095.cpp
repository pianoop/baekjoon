//1, 2, 3 더하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void Sum123(int& total, int n,const int* t)
{
	for (int x, i = 0;i < 3;i++)
	{
		x = n - t[i];
		if (x < 0)
			return;
		if (x == 0)
		{
			total++;
			return;
		}
		else
		{
			Sum123(total, x, t);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	int three[3] = { 1,2,3 };

	while (T--)
	{
		int n, total=0;
		std::cin >> n;

		Sum123(total,n, three);

		std::cout << total << "\n";
	}

	return 0;
}