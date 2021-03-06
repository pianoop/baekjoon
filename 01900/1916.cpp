//최소비용 구하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
class Dis;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<Dis> vD;
typedef std::vector<vD> vvD;

class Dis
{
public:
	int length, idx;

	Dis(int a, int b) :idx(a), length(b) {}
	~Dis() {}

	bool operator<(const Dis& A) const
	{
		return this->length > A.length;
	}
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int unfinded = 0x7FFFFFFF;
	int V, E;
	std::cin >> V >> E;

	vvD graph(V + 1);
	for (int a, b, c, i = 0;i < E;i++)
	{
		std::cin >> a >> b >> c;
		graph[a].push_back(Dis(b, c));
	}
	int A, B;
	std::cin >> A >> B;

	vi ans(V + 1, unfinded);
	ans[A] = 0;
	std::priority_queue<Dis> Box;
	Box.push(Dis(A, 0));

	while (!Box.empty())
	{
		int cost = Box.top().length, nowV = Box.top().idx;
		Box.pop();

		if (cost > ans[nowV])
			continue;

		for (int nextC, nextV, i = 0;i < (int)graph[nowV].size();i++)
		{
			nextV = graph[nowV][i].idx, nextC = graph[nowV][i].length + cost;

			if (ans[nextV] > nextC)
			{
				ans[nextV] = nextC;
				Box.push(Dis(nextV, nextC));
			}
		}
	}

	std::cout << ans[B];

	return 0;
}