//비밀번호 찾기
//-------------------------------------------------------------------
#include <iostream>
#include <unordered_map>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::unordered_map<std::string, std::string> pass;
	std::string s1, s2;
	while (N--)
	{
		std::cin >> s1 >> s2;
		pass[s1] = s2;
	}

	while (M--)
	{
		std::cin >> s1;
		std::cout << pass[s1] << "\n";
	}

	return 0;
}