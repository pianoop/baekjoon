//명령 프롬프트
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

void Solve()
{
	int n;
	std::cin >> n;

	std::vector<std::string> vs(n);

	for (auto& str : vs)
		std::cin >> str;
	std::string ans = vs[0];

	for (int i = 0; i < (int)ans.length(); i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (ans[i] != vs[j][i])
			{
				ans[i] = '?';
				break;
			}
		}
	}

	std::cout << ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}