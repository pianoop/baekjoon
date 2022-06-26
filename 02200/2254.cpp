//감옥 건설
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Pos
{
	int x = 0, y = 0, dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	bool check = false;
};

class Q
{
public:
	Q()
	{
		input();
	}

	~Q()
	{
		delete mPoses;
	}

	void Solve()
	{
		while (!mbFin)
		{
			sorting();
			convexHull();
		}

		cout << mH;
	}


private:
	void input()
	{
		cin >> mN >> mX >> mY;
		mPoses = new vector<Pos>;
		mPoses->resize(mN);

		for (auto& i : *mPoses)
		{
			cin >> i.x >> i.y;
			i.dx2 = i.x - mX;
			i.dy2 = i.y - mX;
		}
	}

	void sorting()
	{
		auto& Poses = *mPoses;
		sort(Poses.begin(), Poses.end(), [](Pos& One, Pos& Other) -> bool
			{
				if (One.y == Other.y)
					return One.x < Other.x;
				return One.y < Other.y;
			});

		int x0 = Poses[0].x, y0 = Poses[0].y;
		for (auto& i : Poses)
		{
			i.dx1 = i.x - x0;
			i.dy1 = i.y - y0;
		}

		sort(Poses.begin() + 1, Poses.end(), [](Pos& One, Pos& Other) -> bool
			{
				ll L = (ll)One.dy1 * Other.dx1, R = (ll)One.dx1 * Other.dy1;
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
		auto& Poses = *mPoses;
		stack<int> hull;
		hull.push(0), hull.push(1);
		
		bool bArea = false;
		int now, prev;
		for (int next = 2; next < mN; next++)
		{
			while (hull.size() > 1)
			{
				now = hull.top();
				hull.pop();
				prev = hull.top();

				if (ccw(Poses[prev], Poses[now], Poses[next]) > 0)
				{
					bArea = true;
					hull.push(now);
					break;
				}
			}

			hull.push(next);
		}

		if (!bArea || (int)hull.size() < 3)
		{
			mbFin = true;
			return; 
		}


		int top = hull.top();
		Pos* A = &Poses[top], *B;
		while (!hull.empty())
		{
			B = &Poses[hull.top()];
			if (ccw2(*A, *B) > 0)
			{
				mbFin = true;
				return;
			}
			
			A = B;
			mN--;
			Poses[hull.top()].check = true;
			hull.pop();
		}

		B = &Poses[top];
		if (ccw2(*A, *B) > 0)
		{
			mbFin = true;
			return;
		}

		mH++;

		if (mN < 3)
		{
			mbFin = true;
			return;
		}

		vector<Pos>* tmp = new vector<Pos>;
		auto& temp = *tmp;
		temp.reserve(mN);
		for (auto& i : Poses)
		{
			if (i.check)
				continue;

			temp.emplace_back(i);
		}
		swap(tmp, mPoses);
		delete tmp;

	}

	ll ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return ll(a.x - b.x) * (a.y - c.y) - ll(a.x - c.x) * (a.y - b.y);
	}

	ll ccw2(const Pos& a, const Pos& b)
	{
		return ll(a.dx2) * b.dy2 - ll(b.dx2) * a.dy2;
	}


private:
	vector<Pos>* mPoses;
	int mN, mH = 0, mX, mY;
	bool mbFin = false;
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