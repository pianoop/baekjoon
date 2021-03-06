//경찰차
//-------------------------------------------------------------------
1)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int abs1(const int& a)
{
	return a > 0 ? a : -a;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int Max = 2000000;
	int N, W;
	std::cin >> N >> W;

	std::vector<std::pair<int, int >> events(W + 1);
	std::for_each(events.begin() + 1, events.end(), [](auto& a)
		{
			std::cin >> a.first >> a.second;
		});

	vvi dist1(W + 1, vi(W + 1));
	for (int i = 1;i < W;i++)
	{
		for (int j = i + 1;j < W + 1;j++)
		{
			dist1[i][j] = abs1(events[i].first - events[j].first) + abs1(events[i].second - events[j].second);
		}
	}

	vvi dist2 = dist1;
	for (int i = 1;i < W + 1;i++)
	{
		dist1[0][i] = events[i].first + events[i].second - 2;
		dist2[0][i] = N * 2 - events[i].first - events[i].second;
	}

	vvi DP(W + 1, vi(W + 1));
	DP[1][0] = dist1[0][1];
	DP[0][1] = dist2[0][1];
	vvi temp(W + 1, vi(W + 1));
	temp[1][0] = temp[0][1] = 0;
	for (int i = 2;i < W + 1;i++)
	{
		int Min1 = Max, Min2 = Max, temp1 = 0, temp2 = 0;
		for (int j = 0;j < i - 1;j++)
		{
			DP[i][j] = DP[i - 1][j] + dist1[i - 1][i];
			DP[j][i] = DP[j][i - 1] + dist2[i - 1][i];
			if (Min1 > DP[i - 1][j] + dist2[j][i])
			{
				Min1 = DP[i - 1][j] + dist2[j][i];
				temp1 = j;
			}
			if (Min2 > DP[j][i - 1] + dist1[j][i])
			{
				Min2 = DP[j][i - 1] + dist1[j][i];
				temp2 = j;
			}
		}
		DP[i - 1][i] = Min1;
		DP[i][i - 1] = Min2;
		temp[i - 1][i] = temp1;
		temp[i][i - 1] = temp2;
	}

	int Min = Max, a = 0, b = 0;
	for (int i = 0;i < W;i++)
	{
		if (Min > DP[W][i])
		{
			Min = DP[W][i];
			a = W, b = i;
		}
		if (Min > DP[i][W])
		{
			Min = DP[i][W];
			a = i, b = W;
		}
	}
	std::cout << Min<<"\n";

	std::stack<int> ans;
	while (a != 0 || b != 0)
	{
		if (a == W)
		{
			ans.push(1);
			if (a - b > 1)
				a--;
			else
				a = temp[a][b];
		}
		else
		{
			ans.push(2);
			if (b - a > 1)
				b--;
			else
				b = temp[a][b];
		}
		W--;
	}

	while (!ans.empty())
	{
		std::cout << ans.top() << "\n";
		ans.pop();
	}

	return 0;
}

-------------------------------------------------------------------
2)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int abs1(const int& a)
{
	return a > 0 ? a : -a;
}

int Dist(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return abs1(a.first - b.first) + abs1(a.second - b.second);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int Max = 2000000;
	int N, W;
	std::cin >> N >> W;

	std::vector<std::pair<int, int >> events(W + 1);
	std::for_each(events.begin() + 1, events.end(), [](auto& a)
		{
			std::cin >> a.first >> a.second;
		});

	vvi DP(W + 1, vi(W + 1));
	DP[1][0] = Dist({ 1,1 }, events[1]);
	DP[0][1] = Dist({ N,N }, events[1]);
	vvi temp(W + 1, vi(W + 1));
	temp[1][0] = temp[0][1] = 0;
	for (int i = 2;i < W + 1;i++)
	{
		int Min1 = Max, Min2 = Max, temp1 = 0, temp2 = 0;
		int tempd = Dist(events[i - 1], events[i]);
		DP[i][0] = DP[i - 1][0] + tempd;
		DP[0][i] = DP[0][i - 1] + tempd;
		tempd = Dist({ N,N }, events[i]);
		if (Min1 > DP[i - 1][0] + tempd)
		{
			Min1 = DP[i - 1][0] + tempd;
			temp1 = 0;
		}
		tempd = Dist({ 1,1 }, events[i]);
		if (Min2 > DP[0][i - 1] + tempd)
		{
			Min2 = DP[0][i - 1] + tempd;
			temp2 = 0;
		}
		for (int j = 1;j < i - 1;j++)
		{
			int tempD = Dist(events[i - 1], events[i]);
			DP[i][j] = DP[i - 1][j] + tempD;
			DP[j][i] = DP[j][i - 1] + tempD;
			tempD = Dist(events[j], events[i]);
			if (Min1 > DP[i - 1][j] + tempD)
			{
				Min1 = DP[i - 1][j] + tempD;
				temp1 = j;
			}
			if (Min2 > DP[j][i - 1] + tempD)
			{
				Min2 = DP[j][i - 1] + tempD;
				temp2 = j;
			}
		}
		DP[i - 1][i] = Min1;
		DP[i][i - 1] = Min2;
		temp[i - 1][i] = temp1;
		temp[i][i - 1] = temp2;
	}

	int Min = Max, a = 0, b = 0;
	for (int i = 0;i < W;i++)
	{
		if (Min > DP[W][i])
		{
			Min = DP[W][i];
			a = W, b = i;
		}
		if (Min > DP[i][W])
		{
			Min = DP[i][W];
			a = i, b = W;
		}
	}
	std::cout << Min << "\n";

	std::stack<int> ans;
	while (a != 0 || b != 0)
	{
		if (a == W)
		{
			ans.push(1);
			if (a - b > 1)
				a--;
			else
				a = temp[a][b];
		}
		else
		{
			ans.push(2);
			if (b - a > 1)
				b--;
			else
				b = temp[a][b];
		}
		W--;
	}

	while (!ans.empty())
	{
		std::cout << ans.top() << "\n";
		ans.pop();
	}

	return 0;
}