//볼록 껍질
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef std::vector<int> vi;
using namespace std;

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

		std::cout << hull.size();
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
				ll L = ll(One.Dy) * Other.Dx, R = ll(One.Dx) * Other.Dy;
				if (L == R)
				{
					if (One.y == Other.y)
						return One.x < Other.x;
					return One.y < Other.y;
				}

				return L < R;
			});
	}

	// 평행, 시계방향 동일 취급 (false)
	inline bool ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return ll(a.x - b.x) * (a.y - c.y) - ll(a.x - c.x) * (a.y - b.y) > 0;
	}


private:
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