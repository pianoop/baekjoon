//별자리 만들기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
typedef std::vector<int > vi;
typedef std::tuple<float, int, int> tup;
typedef std::pair<float, float> pf;

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

float distance(const pf& a, const pf& b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n;
	std::cin >> n;

	std::vector<pf> posbox(n);
	for (auto& [a, b] : posbox)
		std::cin >> a >> b;

	std::vector<tup> dist;
	dist.reserve(n * n / 2 + 1);
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			dist.push_back({ distance(posbox[i],posbox[j]),i,j });
		}
	}

	std::sort(dist.begin(), dist.end());
	int cnt=1;
	float ans = 0;
	vi head(n, -1);
	for (int i = 0;i<int(dist.size());i++)
	{
		float cost;
		int a, b;
		std::tie(cost, a, b) = dist[i];
		if (Merge_CheckGroup(a, b, head))
		{
			ans += cost;
			cnt++;
			if (cnt == n)
				break;
		}
	}

	std::cout << ans;

	return 0;
}