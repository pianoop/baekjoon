//백터 매칭
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>

double Dist(long long x, long long y)
{
	return sqrt(x * x + y * y);
}

class Pos2
{
public:
	Pos2() :x(0), y(0) {}
	Pos2(int a, int b) :x(a), y(b) {}

	void Sum(const Pos2& other)
	{
		x += other.x;
		y += other.y;
	}

	int x, y;
};
typedef std::vector<Pos2> vP;

void Input(const int& N, vP& vpos, Pos2& total)
{
	for (auto& p : vpos)
	{
		std::cin >> p.x >> p.y;
		total.Sum(p);
	}
}

void MatchVector(int n, int idx, int x, int y, double& ans, const int& N, const Pos2& total, const vP& vpos)
{
	if (n == 0)
	{
		double temp = Dist(total.x - 2 * x,total.y - 2 * y);
		if (temp < ans)
			ans = temp;
		return;
	}

	for (int i = idx + 1; i <= N - n; i++)
	{
		MatchVector(n - 1, i, x + vpos[i].x, y + vpos[i].y, ans, N, total, vpos);
	}
}

void Solve()
{
	int N;
	std::cin >> N;

	Pos2 total{ 0,0 };
	vP vpos(N);
	Input(N, vpos, total);

	double ans = 1e10;
	MatchVector(N / 2, -1, 0, 0, ans, N, total, vpos);
	printf("%.8f\n", ans);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		Solve();
	}

	return 0;
}