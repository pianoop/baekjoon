//패션왕 신해빈
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);

	while (N--)
	{
		int n, total = 1;
		scanf("%d", &n);
		std::vector<std::string> vs1;
		std::vector<std::string>::iterator iter;
		std::vector<int> vs2(n, 0);
		std::string s1;
		for (int i = 0;i < n;i++)
		{
			std::cin >> s1 >> s1;
			iter= std::find(vs1.begin(), vs1.end(), s1);
			if (iter == vs1.end())
			{
				vs2[vs1.end() - vs1.begin()]++;
				vs1.push_back(s1);
			}
			else
			{
				vs2[iter - vs1.begin()]++;
			}
		}
		for (int i = 0;i < int(vs1.size());i++)
		{
			total *= (vs2[i] + 1);
		}
		printf("%d\n", --total);
	}

	return 0;
}