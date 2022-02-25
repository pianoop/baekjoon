//케빈 베이컨의 6단계 법칙
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	vvi connect(N + 1);
	vi check(N + 1);

	for (int x,y,i = 0;i < M;i++)
	{
		std::cin >> x >> y;
		connect[x].push_back(y);
		connect[y].push_back(x);
	}

	int Min = 10000, ans=0;
	std::queue<int> box;
	for (int i = 1;i <= N;i++)
	{
		box.push(i);
		check[i] = 1;
		int x, total= 1;
		while (!box.empty())
		{
			x = box.front();

			for (auto& a : connect[x])
			{
				if (check[a] == 0)
				{
					total += check[a] = check[x] + 1;
					box.push(a);
				}
			}

			box.pop();
		}
		if (total < Min)
		{
			ans = i;
			Min = total;
		}
		vi(N + 1).swap(check);
	}
	std::cout << ans;

	return 0;
}