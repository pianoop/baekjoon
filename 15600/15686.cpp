//치킨 배달
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;

int Distance(const pii& a, const pii& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void Distupdate(const int& nowchidx, vi& dist, const vvi& DP, const int& hnum)
{
	for (int i = 0;i < hnum;i++)
	{
		if (dist[i] > DP[nowchidx][i])
			dist[i] = DP[nowchidx][i];
	}
}

void Mindist(int nowchidx, int n, vi dist, const vvi& DP, vi& check, const int& hnum, const int& chnum, int& Minans)
{
	n--;
	Distupdate(nowchidx, dist, DP, hnum);

	if (n == 0)
	{
		int sum = 0;
		for (auto& a : dist)
			sum += a;

		if (Minans > sum)
			Minans = sum;

		return;
	}

	for (;nowchidx < chnum;nowchidx++)
	{
		if (check[nowchidx] == 0)
		{
			check[nowchidx] = 1;
			Mindist(nowchidx, n, dist, DP, check, hnum, chnum, Minans);

			check[nowchidx] = 0;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::vector<pii> chick, house;
	chick.reserve(13);
	house.reserve(2 * N);
	for (int i = 0;i < N;i++)
	{
		for (int x, j = 0;j < N;j++)
		{
			std::cin >> x;
			if (x == 1)
			{
				house.push_back({ i,j });
			}
			else if (x == 2)
			{
				chick.push_back({ i,j });
			}
		}
	}
	int hnum = int(house.size()), chnum = int(chick.size());
	vvi DP(chnum, vi(hnum));

	for (int i = 0;i < chnum;i++)
	{
		for (int j = 0;j < hnum;j++)
		{
			DP[i][j] = Distance(chick[i], house[j]);
		}
	}

	int ans = 100000;
	vi dists(hnum,100), check(chnum);
	for (int i = 0;i < chnum - M + 1;i++)
	{
		Mindist(i, M, dists, DP, check, hnum, chnum, ans);
	}

	std::cout << ans;

	return 0;
}