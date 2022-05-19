//서로 다른 부분 문자열의 개수
//-------------------------------------------------------------------
#include <iostream>
#include <set>


void Solve()
{
	std::string str;
	std::cin >> str;

	int end = int(str.length());
	std::set<std::string> S;
	for (int i = 0; i < end; i++)
	{
		for (int j = 1; j <= end - i; j++)
		{
			S.insert(str.substr(i, j));
		}
	}
	
	std::cout << int(S.size());
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}