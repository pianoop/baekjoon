//집합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vi check(21);
	std::string s1;

	while (N--)
	{
		std::cin >> s1;

		if (s1[1] == 'l')
			vi(21, 1).swap(check);
		else if (s1[1] == 'm')
			vi(21, 0).swap(check);
		else
		{
			int x;
			std::cin >> x;
			if (s1[1] == 'd')
				check[x] = 1;
			else if (s1[1] == 'e')
				check[x] = 0;
			else if (s1[1] == 'h')
			{
				if (check[x] == 1)
					std::cout << "1\n";
				else
					std::cout << "0\n";
			}
			else
			{
				if (check[x] == 1)
					check[x] = 0;
				else
					check[x] = 1;
			}
		}
	}

	return 0;
}