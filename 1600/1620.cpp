//나는야 포켓몬 마스터 이다솜
//-------------------------------------------------------------------
#include <iostream>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n,m;
	std::cin >> n >> m;

	std::map<std::string,int> msi1;
	std::map<int, std::string> mis1;
	std::string s1;
	for (int i = 1;i <= n;i++)
	{
		std::cin >> s1;
		msi1.insert({ s1,i });
		mis1.insert({ i,s1 });
	}

	for (int i = 0;i < m;i++)
	{
		std::cin >> s1;
		if (s1[0] > 58)
		{
			std::cout << msi1[s1] << "\n";
		}
		else
		{
			int x=0, ten=1;
			while (!s1.empty())
			{
				x += ten*((s1.back()-48));
				ten *= 10;
				s1.pop_back();
			}
			std::cout << mis1[x] << "\n";
		}
	}
	
	return 0;
}