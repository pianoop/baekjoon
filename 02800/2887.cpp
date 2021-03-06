//행성 터널
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::pair<int, int> pi;

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

class Tuple
{
public:
	int _x, _y, _z, _idx;

	Tuple() :_x(0), _y(0), _z(0), _idx(0) {}
	Tuple(const int& a, const int& b, const int& c, const int& d) :_x(a), _y(b), _z(c), _idx(d) {}

};

bool cmpx(const Tuple& a, const Tuple& b)
{
	return a._x < b._x;
}
bool cmpy(const Tuple& a, const Tuple& b)
{
	return a._y < b._y;
}
bool cmpz(const Tuple& a, const Tuple& b)
{
	return a._z < b._z;
}

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

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int idx = 0;
	std::vector<Tuple> posbox(N);
	for (auto& [a, b, c, d] : posbox)
	{
		std::cin >> a >> b >> c;
		d = idx++;
	}


	std::vector<Tri> graph;
	graph.reserve(N * 3);
	std::sort(posbox.begin(), posbox.end(), cmpx);
	for (int i = 1;i < N;i++)
	{
		graph.push_back({ posbox[i]._x - posbox[i - 1]._x, posbox[i]._idx, posbox[i - 1]._idx });
	}
	std::sort(posbox.begin(), posbox.end(), cmpy);
	for (int i = 1;i < N;i++)
	{
		graph.push_back({ posbox[i]._y - posbox[i - 1]._y, posbox[i]._idx, posbox[i - 1]._idx });
	}
	std::sort(posbox.begin(), posbox.end(), cmpz);
	for (int i = 1;i < N;i++)
	{
		graph.push_back({ posbox[i]._z - posbox[i - 1]._z, posbox[i]._idx, posbox[i - 1]._idx });
	}

	std::sort(graph.begin(), graph.end());
	int cnt = 1;
	long long cost = 0;
	vi head(N, -1);
	for (int i = 0;i<int(graph.size());i++)
	{
		if (Merge_CheckGroup(graph[i]._a, graph[i]._b, head))
		{
			cost += graph[i]._cost;
			cnt++;
			if (cnt == N)
				break;
		}
	}

	std::cout << cost;

	return 0;
}