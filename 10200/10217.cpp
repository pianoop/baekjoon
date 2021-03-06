//KCM Travel
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <array>
class Trp;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::array<std::array<int, 10001>, 101> aai;
typedef std::array<std::vector<Trp>, 101> aT;

int N, M;
aT map;
aai DP;

class Trp
{
public:
	int f, cost, time;

	Trp(int a, int b, int c) :f(a), cost(b), time(c) {}
	~Trp() {}

	bool operator<(const Trp& b) const
	{
		if (this->time == b.time)
			return this->cost < b.cost;
		return this->time > b.time;
	}
};

int Dijkstra()
{
	std::priority_queue<Trp> Box;
	Box.push({ 1, 0, 0 });
	int ans = 0;
	while (!Box.empty())
	{
		auto now = Box.top();
		Box.pop();

		if (DP[now.f][now.cost] < now.time)
			continue;
		if (now.f == N)
		{
			ans = now.time;
			break;
		}

		for (auto& next : map[now.f])
		{
			int NC = now.cost + next.cost, NT = now.time + next.time;
			int c = NC;
			for (;c<M && DP[next.f][c] > NT; c++)
				DP[next.f][c] = NT;
			if (c != NC)
				Box.push({ next.f, NC, NT });
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	const int INF = 1000000;
	while (T--)
	{
		int K;
		std::cin >> N >> M >> K;
		M++;
		for (int i = 1;i < N + 1;i++)
			map[i].clear();
		for (int a, b, c, d, i = 0;i < K;i++)
		{
			std::cin >> a >> b >> c >> d;
			map[a].push_back(Trp(b,c,d));
		}

		for (int i = 0;i < M;i++)
			DP[1][i] = 0;
		for (int i = 1;i < N + 1;i++)
			for (int j = 0;j < M;j++)
				DP[i][j] = INF;

		int ans = Dijkstra();

		if (ans == 0)
			std::cout << "Poor KCM\n";
		else
			std::cout << ans << "\n";
	}

	return 0;
}