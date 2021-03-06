//경로 찾기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void mapping(const int& i, int j, const vvi& map, vvi& ans)
{
	for (auto& a : map[j])
	{
		if (ans[i][a]==0)
		{
			ans[i][a] = 1;
			mapping(i,a, map, ans);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vvi map(N);
	for (int x, i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			std::cin >> x;
			if (x == 1)
				map[i].push_back(j);
		}
	}
	
	vvi ans(N, vi(N));
	for (int i = 0;i < N;i++)
	{
		if (!map[i].empty())
		{
			mapping(i,i,map, ans);
		}
	}

	for (auto& a : ans)
	{
		for (auto& b : a)
			std::cout << b << " ";
		std::cout << "\n";
	}

	return 0;
}