//보석 도둑
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef std::vector<pi> vpi;

void Input(vi& bag, vpi& jewels)
{
	for (auto& [m, v] : jewels)
		std::cin >> m >> v;
	for (auto& m : bag)
		std::cin >> m;
}

void Solve()
{
	int N, K;
	std::cin >> N >> K;

	vi bag(K);
	vpi jewels(N);
	Input(bag, jewels);
	
	std::sort(jewels.begin(), jewels.end(), [](const pi& a, const pi& b)->bool
		{
			return a.first < b.first;
		});
	std::sort(bag.begin(), bag.end());

	long long ans = 0;
	std::priority_queue<int> pq;
	for (int i = 0, j = 0; i<int(bag.size()); i++)
	{
		for (; j < int(jewels.size()); j++)
		{
			if (bag[i] >= jewels[j].first)
				pq.push(jewels[j].second);
			else
				break;
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%lld", ans);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}