//다리 만들기 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

int min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int abs1(const int& a)
{
	return a > 0 ? a : -a;
}

class Tri
{
public:
	int _cost, _a, _b;

	Tri(const int& cost, const int& a, const int& b) :_cost(cost), _a(a), _b(b) {}

	bool operator<(const Tri& other)
	{
		return _cost < other._cost;
	}
};

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

void bridge(const int& toward, int n, int m, const int& a, vvi& DP, const vvi& map)  //to 0,1->가로+-, 2,3->세로+-, +-는 Matrix 기준
{
	int block = 1, b;
	if (toward == 0)
	{
		while (true)
		{
			m++;
			if (map[n][m] < -1)
			{
				b = -map[n][m];
				break;;
			}
			else if (map[n][m] == -1)
				return;

			block++;
		}
	}
	else if (toward == 1)
	{
		while (true)
		{
			m--;
			if (map[n][m] < -1)
			{
				b = -map[n][m];
				break;;
			}
			else if (map[n][m] == -1)
				return;

			block++;
		}
	}
	else if (toward == 2)
	{
		while (true)
		{
			n++;
			if (map[n][m] < -1)
			{
				b = -map[n][m];
				break;;
			}
			else if (map[n][m] == -1)
				return;

			block++;
		}
	}
	else
	{
		while (true)
		{
			n--;
			if (map[n][m] < -1)
			{
				b = -map[n][m];
				break;;
			}
			else if (map[n][m] == -1)
				return;

			block++;
		}
	}

	if (block < 2)
		return;
	if (block < DP[a][b])
		DP[a][b] = block;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	vvi map(N + 2, vi(M + 2, -1));  //외곽 -1처리
	std::for_each(map.begin() + 1, map.end() - 1, [&map](auto& a)
		{
			std::for_each(a.begin() + 1, a.end() - 1, [](auto& b)
				{
					std::cin >> b;
					if (b == 1)
						b = -2;
				});
		});

	int nextn[4] = { 0,0,1,-1 }, nextm[4] = { 1,-1,0,0 };
	int isidx = 3;  //섬 번호는 3번부터 시작!, 섬 갯수는 isidx-3개;
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= M;j++)
		{
			if (map[i][j] == -2)
			{
				map[i][j] = isidx;
				std::queue<pi> bfsbox;
				bfsbox.push({ i, j });

				while (!bfsbox.empty())
				{
					int n, m;
					std::tie(n, m) = bfsbox.front();
					bfsbox.pop();

					for (int i = 0;i < 4;i++)
					{
						int nn = n + nextn[i], nm = m + nextm[i];
						if (map[nn][nm] == -2)
						{
							map[nn][nm] = isidx;
							bfsbox.push({ nn, nm });
						}
						else if (map[nn][nm] == 0)
						{
							map[n][m] = -isidx;   //외곽 표시
						}
					}
				}
				isidx++;
			}
		}
	}

	vvi DP(isidx, vi(isidx, 1000));  //[a][b]=cost 간선
	for (int i = 1;i < N + 1;i++)
	{
		for (int j = 1;j < M + 1;j++)
		{
			if (map[i][j] < -1)
			{
				for (int k = 0;k < 4;k++)
				{
					int nn = i + nextn[k], nm = j + nextm[k];
					if (map[nn][nm] == 0)
					{
						bridge(k, nn, nm, -map[i][j], DP, map);
					}
				}
			}
		}
	}

	map.shrink_to_fit();
	std::vector<Tri> bridge;
	bridge.reserve(isidx*isidx/2+1);
	for (int i = 3;i < isidx;i++)
	{
		for (int j = i + 1;j < isidx;j++)
		{
			if (DP[i][j] != 1000)
				bridge.push_back({ DP[i][j],i,j });
		}
	}



	DP.shrink_to_fit();
	std::sort(bridge.begin(), bridge.end());
	int cnt = 1, cost=0;
	vi head(isidx , -1);
	isidx -= 3;				 //실제 섬의 개수로 변경
	for (int i = 0;i<int(bridge.size());i++)
	{
		if (Merge_CheckGroup(bridge[i]._a, bridge[i]._b, head))
		{
			cost += bridge[i]._cost;
			cnt++;
			if (cnt == isidx)
				break;
		}
	}

	if (cnt == isidx)
		std::cout << cost;
	else
		std::cout << -1;

	return 0;
}