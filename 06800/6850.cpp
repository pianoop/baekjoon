//Cows
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Pos
{
	int y = 0, x = 0, Dx = 0, Dy = 0;
};

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		convexHull();

		int ans = 0, end = (int)mHull.size() - 1, next = 1;
		for (int now = 0; next < end;)
		{
			auto& dot1 = mHull[now];
			auto& dot2 = mHull[next];
			ans += abs(dot1.Dx * dot2.Dy - dot1.Dy * dot2.Dx);

			now = next++;
		}

		cout << ans / 100;
	}


private:
	void input()
	{
		cin >> mN;

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
			mHull.push_back(mPoses[hull.top()]);
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

	inline double dist(const pii& pos1, const pii& pos2)
	{
		return sqrt(mPow(pos1.first - pos2.first) + mPow(pos1.second - pos2.second));
	}

private:
	vector<Pos> mPoses, mHull;
	int mN;

};

void Solve()
{
	Q q;
	q.Solve();
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}