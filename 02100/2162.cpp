//선분 그룹
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> pi;
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

class Pos
{
public:
	int x, y;

	Pos() :x(0), y(0) {}
	Pos(int a, int b) :x(a), y(b) {}

	bool operator >(const Pos& other)
	{
		if (x == other.x)
			return y > other.y;
		return x > other.x;
	}

	bool operator <=(const Pos& other)
	{
		return !(*this > other);
	}
};

class Line
{
public:
	Pos start, end;

	Line(int a, int b, int c, int d) 
	{
		start = Pos(a,b), end = Pos(c,d) ;
		if (start > end)
			std::swap(start, end);
	}

	pi Ccw(const Line& other)
	{
		int a = (end.x - start.x) * (other.start.y - start.y) - (other.start.x - start.x) * (end.y - start.y);
		int b = (end.x - start.x) * (other.end.y - start.y) - (other.end.x - start.x) * (end.y - start.y);
		if (a > 0)
			a = 1;
		else if (a < 0)
			a = -1;
		if (b > 0)
			b = 1;
		else if (b < 0)
			b = -1;

		return { a,b };
	}
};

bool Intersection(Line& A, Line& B)
{
	pi a = A.Ccw(B), b = B.Ccw(A);

	if (a.first * a.second == 0 && b.first * b.second == 0)
	{
		if (B.start <= A.end && A.start <= B.end)
			return 1;
		else
			return 0;
	}
	else if (a.first * a.second <= 0 && b.first * b.second <= 0)
		return 1;
	else
		return 0;
}

int Find(const int& a, vi& head)
{
	if (head[a] < 0)
		return a;

	return head[a] = Find(head[a], head);
}

void Merge(int a, int b, vi& head)
{
	a = Find(a, head), b = Find(b, head);
	if (a == b)
		return;

	head[a] += head[b];
	head[b] = a;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<Line> Linebox;
	Linebox.reserve(N);
	for (int i = 0;i < N;i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		Linebox.push_back({a, b, c, d});
	}

	vi head(N,-1);
	for (int i=0;i<N;i++)
	{
		for (int j = i+1;j < N;j++)
		{
			if (Intersection(Linebox[i], Linebox[j]))
				Merge(i, j, head);
		}
	}

	int groupnum = 0, Max=0;
	for (auto& a : head)
	{
		if (a < 0)
		{
			groupnum++;
			if (Max > a)
				Max = a;
		}
	}

	std::cout << groupnum << "\n" << -Max;

	return 0;
}