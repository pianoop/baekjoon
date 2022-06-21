//달리기 코스
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
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

		ll Max = 0;
		int dx, dy;
		for (int i = 0; i < mHull.size(); i++)
		{
			auto [x0, y0] = mHull[i];
			x0 = -x0;
			y0 = -y0;

			for (int j = i + 1; j < mHull.size(); j++)
			{
				auto& now = mHull[j];
				dx = now.first + x0, dy = now.second + y0;

				Max = max(Max, (ll)dx * dx + (ll)dy * dy);
			}
		}
		

		cout << Max;
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
				ll L = (ll)One.Dy * Other.Dx, R = (ll)One.Dx * Other.Dy;
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
		return ll(a.x - b.x) * (a.y - c.y) - ll(a.x - c.x) * (a.y - b.y) > 0;
	}


private:
	vector<pair<int, int> > mHull;
	vector<Pos> mPoses;
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