//우주신과의 교감
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
typedef double ld;
typedef std::vector<int > vi;
typedef std::tuple<ld, int, int> tup;
typedef std::pair<int, int> pi;

int find(const int& a, vi& head)
{
	if (head[a] < 0)
		return a;

	return head[a] = find(head[a], head);
}

bool Merge_CheckGroup(int a, int b, vi& head)
{
	a = find(a, head), b = find(b, head);
	if (a == b)
		return 0;

	head[a] += head[b];
	head[b] = a;
	return 1;
}

ld distance(const pi& a, const pi& b)
{
	return sqrt(pow(ld(a.first) - b.first, 2) + pow((ld)a.second - b.second, 2));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::vector<pi> posbox(N + 1);
	std::for_each(posbox.begin() + 1, posbox.end(), [&posbox](auto& a)
		{
			std::cin >> a.first >> a.second;
		});

	std::vector<tup> dist;
	dist.reserve(N * N / 2 + 2);
	for (int i = 1;i <= N;i++)
	{
		for (int j = i + 1;j <= N;j++)
		{
			dist.push_back({ distance(posbox[i],posbox[j]),i,j });
		}
	}
	int cnt = 1;
	vi head(N + 1, -1);
	for (int i = 0;i < M;i++)
	{
		int a, b;
		std::cin >> a >> b;
		if (Merge_CheckGroup(a, b, head))
			cnt++;
	}

	if (cnt == N)
	{
		std::cout << "0.00";
		return 0;
	}

	std::sort(dist.begin(), dist.end());
	ld ans = 0;
	for (int i = 0;i < int(dist.size());i++)
	{
		ld cost;
		int a, b;
		std::tie(cost, a, b) = dist[i];
		if (Merge_CheckGroup(a, b, head))
		{
			ans += cost;
			cnt++;
			if (cnt == N)
				break;
		}
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << ans;

	return 0;
}