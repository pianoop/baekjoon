//도시 분할 계획
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;

class Edge
{
public:
	Edge(int a, int b, int cost) :ma(a), mb(b), mcost(cost) {}

	bool operator<(const Edge& other) const
	{
		return mcost > other.mcost;
	}

	int ma, mb, mcost;
};

class Union
{
public:
	Union(int n) :mN(n)
	{
		mheads.resize(n + 1, -1);
	}

	int Findhead(int a)
	{
		if (mheads[a] < 0)
			return a;

		return mheads[a] = Findhead(mheads[a]);
	}

	bool Merge(int a, int b)
	{
		a = Findhead(a);
		b = Findhead(b);

		if (a == b)
			return 0;

		mheads[a] += mheads[b];
		mheads[b] = a;
		return 1;
	}
private:
	int mN;
	vi mheads;
};

void Solve()
{
	int N, M;
	std::cin >> N >> M;
	std::priority_queue<Edge> edges;
	for (int i = 0; i < M; i++)
	{
		int a, b, cost;
		std::cin >> a >> b >> cost;
		edges.push({ a,b,cost });
	}
	
	int totalcost = 0, mergecnt = 0;
	Union uni(N);

	while (true)
	{
		auto now = edges.top();

		if (uni.Merge(now.ma, now.mb))
		{
			mergecnt++;
			totalcost += now.mcost;
			if (mergecnt == N - 2)
				break;
		}
		edges.pop();
	}
	printf("%d", totalcost);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}