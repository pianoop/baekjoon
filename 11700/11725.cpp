//트리의 부모 찾기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N;
	std::cin >> N;

	vvi treebox(N + 1);
	for (int a, b, i = 1;i < N;i++)
	{
		std::cin >> a >> b;
		treebox[a].push_back(b);
		treebox[b].push_back(a);
	}
	
	vi ans(N + 1),check(N+1);
	ans[1] = -1;

	std::queue<int> box;
	box.push(1);

	int now;
	while (!box.empty())
	{
		now = box.front();
		box.pop();
		if (check[now] == 0)
		{
			check[now] = 1;
			for (auto& a : treebox[now])
			{
				if (ans[a] == 0)
				{
					box.push(a);
					ans[a] = now;
				}
			}
		}
	}

	std::for_each(ans.begin() + 2, ans.end(), [](auto& a)
		{
			std::cout << a << "\n";
		});

	return 0;
}