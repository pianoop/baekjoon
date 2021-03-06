//치즈
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M, ans = 0;
	std::cin >> N >> M;
	vvi gridP(N + 2, vi(M + 2, -1));
	std::for_each(gridP.begin() + 1, gridP.end() - 1, [](auto& a)
		{
			std::for_each(a.begin() + 1, a.end() - 1, [](auto& b)
				{
					std::cin >> b;
				});
		});

	int udlrx[4] = { 0, 0, -1, 1 }, udlry[4] = { -1, 1, 0, 0 };
	while (true)
	{
		std::queue<std::pair<int, int> > Boxair, BoxCh;
		Boxair.push({ 1,1 });
		vvi check(N + 2, vi(M + 2));
		while (!Boxair.empty())
		{
			auto now = Boxair.front();
			Boxair.pop();

			for (int nn, nm, i = 0;i < 4;i++)
			{
				nn = now.first + udlry[i], nm = now.second + udlrx[i];
				if (check[nn][nm] == 0 || check[nn][nm] > 1)
				{
					if (gridP[nn][nm] == 1)
					{
						if (check[nn][nm] > 1)
							check[nn][nm]++;
						else
						{
							BoxCh.push({ nn,nm });
							check[nn][nm] = 2;
						}
					}
					else
					{
						check[nn][nm] = 1;
						if (gridP[nn][nm] == 0)
						{
							gridP[nn][nm] = 2;
							Boxair.push({ nn,nm });
						}
						else if (gridP[nn][nm] == 2)
						{
							Boxair.push({ nn,nm });
						}
					}
				}
			}
		}
		if (!BoxCh.empty())
		{
			ans++;
			while (!BoxCh.empty())
			{
				auto tmp = BoxCh.front();
				BoxCh.pop();
				if (check[tmp.first][tmp.second] > 2)
					gridP[tmp.first][tmp.second] = 2;
			}
		}
		else
			break;

	}

	std::cout << ans;

	return 0;
}