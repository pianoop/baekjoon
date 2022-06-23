//고속도로
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
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
		int top, bot;
		top = convexHull();
		bot = (int)mHull.size() - 1;
		calipers(top, bot);
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

	int convexHull()
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

		int maxH = INT_MIN, top = 0;
		mHull.reserve(hull.size());
		while (!hull.empty())
		{
			auto& now = mPoses[hull.top()];
			mHull.push_back({ now.x, now.y });
			
			if (now.y > maxH)
			{
				maxH = now.y;
				top = (int)mHull.size();
			}
			hull.pop();
		}

		return top - 1;
	}

	void calipers(int top, int bot)
	{
		int ans1 = top, ans2 = bot;
		ll Max = distSq(mHull[top], mHull[bot]), dist;

		const int SIZE = (int)mHull.size();
		pi* t1 = &mHull[top],  *t2 = &mHull[(top + 1) % SIZE], *b1 = &mHull[bot], *b2 = &mHull[(bot + 1) % SIZE];
		int dx1 = t2->first - t1->first
			, dy1 = t2->second - t1->second
			, dx2 = b1->first - b2->first
			, dy2 = b1->second - b2->second
			, nextTop = (top + 1) % SIZE
			, nextBot = (bot + 1) % SIZE;

		for (int i = 0; i < SIZE; i++)
		{
			if (ll(dx1) * dy2 - ll(dx2) * dy1 < 0) //top이 전진 (반시계)
			{
				top = nextTop;
				nextTop = (top + 1) % SIZE;
				t1 = t2;
				t2 = &mHull[nextTop];
				dx1 = t2->first - t1->first, dy1 = t2->second - t1->second;
			}
			else  //bot이 전진
			{
				bot = nextBot;
				nextBot = (bot + 1) % SIZE;
				b1 = b2;
				b2 = &mHull[nextBot];
				dx2 = b1->first - b2->first, dy2 = b1->second - b2->second;
			}

			dist = distSq(*t1, *b1);
			if (dist > Max)
			{
				Max = dist;
				ans1 = top, ans2 = bot;
			}
		}
		std::cout << mHull[ans1].first << " " << mHull[ans1].second << " " 
			<< mHull[ans2].first << " " << mHull[ans2].second << "\n";
	}

	// 평행, 시계방향 동일 취급 (false)
	inline bool ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return ll(a.x - b.x) * (a.y - c.y) - ll(a.x - c.x) * (a.y - b.y) > 0;
	}

	inline ll mPow(int a)
	{
		return (ll)a * a;
	}

	inline ll distSq(const pi& pos1, const pi& pos2)
	{
		return mPow(pos1.first - pos2.first) + mPow(pos1.second - pos2.second);
	}

private:
	vector<pi> mHull;
	vector<Pos> mPoses;
	int mN;

};

void Solve()
{
	int T,n;
	std::cin >> T;
	while (T--)
	{
		std::cin >> n;
		Q q(n);
		q.Solve();
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}