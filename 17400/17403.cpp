//가장 높고 넓은 성
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
	int x = 0, y = 0, dx = 0, dy = 0, idx = 0;
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

		for (auto i : mAns)
			cout << i << " ";
	}


private:
	void input()
	{
		cin >> mN;
		mPoses = new vector<Pos>;
		mPoses->resize(mN);
		mAns.resize(mN);

		int idx = 0;
		for (auto& i : *mPoses)
		{
			i.idx = idx++;
			cin >> i.x >> i.y;
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
		for (auto& [x, y, dx, dy, idx, check] : Poses)
		{
			dx = x - x0;
			dy = y - y0;
		}

		sort(Poses.begin() + 1, Poses.end(), [](Pos& One, Pos& Other) -> bool
			{
				int L = One.dy * Other.dx, R = One.dx * Other.dy;
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

				if (ccw(Poses[prev], Poses[now], Poses[next]))
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

		/*else if (!bArea)
		{
			int next = hull.top();
			hull.pop();
			now = hull.top();
			hull.pop();
			prev = hull.top();

			if (ccw(Poses[prev], Poses[now], Poses[next]))
			{
				hull.push(now);
				hull.push(next);
			}
			else
				break;
		}*/

		while (!hull.empty())
		{
			mN--;
			auto& tmp = Poses[hull.top()];
			tmp.check = true;
			mAns[tmp.idx] = mH;
			hull.pop();
		}

		if (mN < 3)
		{
			mbFin = true;
			return;
		}

		vector<Pos>* tmp = new vector<Pos>;
		auto& temp = *tmp;
		temp.reserve(mN);
		for (auto& [x, y, dx, dy, idx, check] : Poses)
		{
			if (check)
				continue;

			temp.emplace_back(Pos(x, y, 0, 0, idx, false));
		}
		swap(tmp, mPoses);
		delete tmp;

		mH++;
	}

	// 평행, 시계방향 동일 취급 (false)
	inline bool ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return (a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y) > 0;
	}

	inline bool sameAngle(const Pos& One, const Pos& Other)
	{
		int L = One.dy * Other.dx, R = One.dx * Other.dy;
		return L == R;
	}


private:
	vector<Pos>* mPoses;
	vi mAns;
	int mN, mH = 1;
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