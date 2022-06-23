//쓰레기 슈트
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef vector<int> vi;

struct Pos
{
	int y = 0, x = 0, Dx = 0, Dy = 0;
};

class Q
{
public:
	Q(int n) :mN(n)
	{
		input();
	}

	void Solve()
	{
		convexHull();

		// 맨 끝, 맨 앞 계산해두기
		auto [x0, y0] = mHull.back();
		auto [x1, y1] = mHull.front();
		int maxArea = 0, dx = x0 - x1, dy = y0 - y1;
		for (auto& [x, y] : mHull)
			maxArea = max(maxArea, abs(dx * (y0 - y) - dy * (x0 - x)));
		double Min = maxArea / (sqrt(mPow(x0 - x1) + mPow(y0 - y1)));

		int end = (int)mHull.size() - 1;
		for (int i = 0; i < end;)
		{
			auto [x0, y0] = mHull[i++];
			auto [x1, y1] = mHull[i];
			dx = x0 - x1, dy = y0 - y1;
			maxArea = 0;
			for (auto& [x, y] : mHull)
				maxArea = std::max(maxArea, abs(dx * (y0 - y) - dy * (x0 - x)));

			Min = min(Min, (maxArea / (sqrt(mPow(x0 - x1) + mPow(y0 - y1)))));
		}
		
		cout << Min + 0.00499999 << "\n";
	}


private:
	void input()
	{
		mPoses.resize(mN);
		for (auto& [y, x, dx, dy] : mPoses)
			cin >> x >> y;

		sort(mPoses.begin(), mPoses.end(), [](Pos& One, Pos& Other) -> bool
			{
				if (One.y == Other.y)
					return One.x < Other.x;
				return One.y < Other.y;
			});

		int x0 = mPoses[0].x, y0 = mPoses[0].y;
		for (auto& [y, x, dx, dy] : mPoses)
		{
			dx = x - x0;
			dy = y - y0;
		}

		sort(mPoses.begin() + 1, mPoses.end(), [](Pos& One, Pos& Other) -> bool
			{
				int L = One.Dy * Other.Dx, R = One.Dx * Other.Dy;
				if (L == R)
				{
					if (One.y == Other.y)
						return One.x < Other.x;
					return One.y < Other.y;
				}

				return L < R;
			});
	}

	void convexHull()
	{
		stack<int> hull;
		hull.push(0), hull.push(1);

		int now, prev;
		for (int next = 2; next < mN; next++)
		{
			while (hull.size() > 1)
			{
				now = hull.top();
				hull.pop();
				prev = hull.top();

				if (ccw(mPoses[prev], mPoses[now], mPoses[next]))
				{
					hull.push(now);
					break;
				}

			}

			hull.push(next);
		}

		mHull.reserve(hull.size());
		while (!hull.empty())
		{
			auto& now = mPoses[hull.top()];
			mHull.push_back({ now.x, now.y });
			hull.pop();
		}
	}

	// 평행, 시계방향 동일 취급 (false)
	inline bool ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return (a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y) > 0;
	}

	inline int mPow(int a)
	{
		return a * a;
	}


private:
	vector<pair<int, int> > mHull;
	vector<Pos> mPoses;
	int mN;

};

void Solve()
{
	cout.precision(2);
	cout << fixed;

	int T, cnt = 1;
	while (cin >> T)
	{
		if (T == 0)
			break;

		Q q(T);
		std::cout << "Case " << cnt++ << ": ";
		q.Solve();
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}
