//단어 뒤집기
//-------------------------------------------------------------------
#include <iostream>


void Solve()
{
	std::string str;
	
	while (std::cin >> str)
	{
		for (int i = str.length() - 1; i >= 0; i--)
			std::cout<< str.at(i);
		std::cout << " ";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
	{
		Solve();
		std::cout << "\n";
	}

	return 0;
}