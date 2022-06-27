//점 분리
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct Pos
{
	int x = 0, y = 0, Dx = 0, Dy = 0;
};

class Q
{
public:
	Q()
	{
		cin >> mN >> mM;
		input(true, mN);
		input(false, mM);
	}

	void Solve()
	{
		vector<pii> hull1, hull2;
		bool bCheck1 = convexHull(true, mN, hull1);
		bool bCheck2 = convexHull(false, mM, hull2);

		//Convex hull 내부 포함 판정
		bool bEnd = false;
		if (bCheck1 && bCheck2)
			bEnd = dotDoubleCheck(hull1, hull2);
		else if (bCheck1)
			bEnd = dotCheck(false, hull1);
		else if (bCheck2)
			bEnd = dotCheck(true, hull2);

		if (bEnd)
		{
			cout << "NO\n";
			return;
		}


		//선분교차 판정
		if (mPoses1.size() != 1 && mPoses2.size() != 1)
		{
			if (bCheck1 && bCheck2)
				bEnd = lineDoubleCheck(hull1, hull2);
			else if (bCheck1)
				bEnd = lineCheck(false, hull1);
			else if (bCheck2)
				bEnd = lineCheck(true, hull2);
			else
				bEnd = check();
		}
		else if (!bCheck1 && !bCheck2)
		{
			if (mPoses1.size() == 1)
			{
				if (mPoses2.size() != 1)
				{
					sort(mPoses2.begin(), mPoses2.end(), [](auto& a, auto& b) -> bool
						{
							if (a.x == b.x)
								return a.y < b.y;
							return a.x < b.x;
						});

					if (ccw(mPoses2.front(), mPoses2.back(), mPoses1[0]) == 0)
						bEnd = simpleCheck(mPoses2.front(), mPoses2.back(), mPoses1[0]);
				}
			}
			else
			{
				sort(mPoses1.begin(), mPoses1.end(), [](auto& a, auto& b) -> bool
					{
						if (a.x == b.x)
							return a.y < b.y;
						return a.x < b.x;
					});

				if (ccw(mPoses1.front(), mPoses1.back(), mPoses2[0]) == 0)
					bEnd = simpleCheck(mPoses1.front(), mPoses1.back(), mPoses2[0]);
			}
		}

		if (bEnd)
			cout << "NO\n";
		else
			cout << "YES\n";
	}


private:
	void input(bool order, const int n)
	{
		vector<Pos>* tmp;
		if (order)
			tmp = &mPoses1;
		else
			tmp = &mPoses2;
		auto& Poses = *tmp;

		Poses.resize(n);
		for (auto& [x, y, dx, dy] : Poses)
			cin >> x >> y;

		sort(Poses.begin(), Poses.end(), [](Pos& One, Pos& Other) -> bool
			{
				if (One.y == Other.y)
					return One.x < Other.x;
				return One.y < Other.y;
			});

		int x0 = Poses[0].x, y0 = Poses[0].y;
		for (auto& [x, y, dx, dy] : Poses)
		{
			dx = x - x0;
			dy = y - y0;
		}

		sort(Poses.begin() + 1, Poses.end(), [](Pos& One, Pos& Other) -> bool
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

	bool convexHull(bool order, const int n, vector<pii>& hull)
	{
		if (n < 3)
			return false;

		vector<Pos>* tmp;
		if (order)
			tmp = &mPoses1;
		else
			tmp = &mPoses2;
		auto& Poses = *tmp;

		stack<int> stack;
		stack.push(0), stack.push(1);

		int now, prev;
		for (int next = 2; next < n; next++)
		{
			while (stack.size() > 1)
			{
				now = stack.top();
				stack.pop();
				prev = stack.top();

				if (ccw(Poses[prev], Poses[now], Poses[next]) > 0)
				{
					stack.push(now);
					break;
				}

			}

			stack.push(next);
		}

		if ((int)stack.size() < 3)
			return false;

		hull.reserve((int)stack.size() + 1);
		while (!stack.empty())
		{
			auto& tmp = Poses[stack.top()];
			hull.push_back({ tmp.x, tmp.y });
			stack.pop();
		}
		hull.push_back(hull.front());

		return true;
	}

	bool dotDoubleCheck(const vector<pii>& hull1, const vector<pii>& hull2)
	{
		int end = (int)hull2.size() - 1;
		for (auto& Pos1 : hull1)
		{
			bool bCheck = true;
			for (int i = 0; i < end;)
			{
				auto& Pos2 = hull2[i++];
				auto& Pos3 = hull2[i];
				if (ccw(Pos2,Pos3, Pos1) > 0)
				{
					bCheck = false;
					break;
				}
			}

			if (bCheck)
				return true;
		}


		end = (int)hull1.size() - 1;
		for (auto& Pos1 : hull2)
		{
			bool bCheck = true;
			for (int i = 0; i < end;)
			{
				auto& Pos2 = hull1[i++];
				auto& Pos3 = hull1[i];
				if (ccw(Pos2, Pos3, Pos1) > 0)
				{
					bCheck = false;
					break;
				}
			}

			if (bCheck)
				return true;
		}

		return false;
	}

	bool dotCheck(bool order, const vector<pii>& hull)
	{
		vector<Pos>* tmp;
		if (order)
			tmp = &mPoses1;
		else
			tmp = &mPoses2;
		auto& Poses = *tmp;

		int end = (int)hull.size() - 1;
		for (auto& Pos1 : Poses)
		{
			bool bCheck = true;
			for (int i = 0; i < end;)
			{
				auto& Pos2 = hull[i++];
				auto& Pos3 = hull[i];
				if (ccw(Pos2, Pos3, { Pos1.x, Pos1.y }) > 0)
				{
					bCheck = false;
					break;
				}
			}

			if (bCheck)
				return true;
		}

		return false;
	}

	bool lineDoubleCheck(vector<pii>& hull1, vector<pii>& hull2)
	{
		int end1 = (int)hull1.size() - 1, end2 = (int)hull2.size() - 1;
		for (int i = 0; i < end1;)
		{
			pii* p1 = &hull1[i++];
			pii* p2 = &hull1[i];
			for (int j = 0; j < end2;)
			{
				pii* p3 = &hull2[j++];
				pii* p4 = &hull2[j];

				int a = ccw(*p1, *p2, *p3) * ccw(*p1, *p2, *p4)
					,b = ccw(*p3, *p4, *p1) * ccw(*p3, *p4, *p2);

				if (a <= 0 && b <= 0)
				{
					if (a == 0 && b == 0)
					{
						if (ccwException(p1, p2, p3, p4))
							return true;
					}
					else
						return true;
				}
			}
		}


		return false;
	}

	bool lineCheck(bool order, vector<pii>& hull)
	{
		bool bFin = false;

		vector<Pos>* tmp;
		if (order)
			tmp = &mPoses1;
		else
			tmp = &mPoses2;
		auto& Poses = *tmp;

		sort(Poses.begin(), Poses.end(), [](auto& a, auto& b) -> bool
			{
				if (a.x == b.x)
					return a.y < b.y;
				return a.x < b.x;
			});
		pii* p1 = new pii{ Poses[0].x, Poses[0].y }
		, * p2 = new pii{ Poses.back().x, Poses.back().y };

		int end = (int)hull.size() - 1;
		for (int j = 0; j < end;)
		{
			pii* p3 = &hull[j++];
			pii* p4 = &hull[j];

			int a = ccw(*p1, *p2, *p3) * ccw(*p1, *p2, *p4),
				b = ccw(*p3, *p4, *p1) * ccw(*p3, *p4, *p2);

			if (a <= 0 && b <= 0)
			{
				if (a == 0 && b == 0)
				{
					if (ccwException(p1, p2, p3, p4))
						bFin = true;
				}
				else
					bFin = true;
			}
		}

		if (bFin)
			delete p1, p2;

		return bFin;
	}

	bool check()
	{
		sort(mPoses1.begin(), mPoses1.end(), [](auto& a, auto& b) -> bool
			{
				if (a.x == b.x)
					return a.y < b.y;
				return a.x < b.x;
			});
		pii* p1 = new pii{ mPoses1[0].x, mPoses1[0].y }
		, * p2 = new pii{ mPoses1.back().x, mPoses1.back().y };

		sort(mPoses2.begin(), mPoses2.end(), [](auto& a, auto& b) -> bool
			{
				if (a.x == b.x)
					return a.y < b.y;
				return a.x < b.x;
			});
		pii* p3 = new pii{ mPoses2[0].x, mPoses2[0].y }
		, * p4 = new pii{ mPoses2.back().x, mPoses2.back().y };

		bool bAns = ccwException(p1, p2, p3, p4);
		delete p1, p2, p3, p4;

		return bAns;
	}

	inline bool simpleCheck(const Pos& a, const Pos& b, const Pos& c)
	{
		if (a.x == b.x)
		{
			if (a.y < c.y && c.y < b.y)
				return true;
		}
		else
		{
			if (a.x < c.x && c.x < b.x)
				return true;
		}

		return false;
	}

	// 평행, 시계방향 동일 취급 (false)
	inline int ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return (a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y);
	}

	inline int ccw(const pii& a, const pii& b, const pii& c)
	{
		int tmp = (a.first - b.first) * (a.second - c.second) - (a.first - c.first) * (a.second - b.second);
		return tmp > 0 ? 1 : (tmp < 0 ? -1 : 0);
	}

	inline bool ccwException(pii* p1, pii* p2, pii* p3, pii* p4)
	{
		if (p1->first == p2->first)
		{
			if (p1->second > p2->second)
				swap(p1, p2);
			if (p3->second > p4->second)
				swap(p3, p4);

			if (p1->second < p3->second)
			{
				if (p2->second > p3->second)
					return true;
			}
			else
			{
				if (p4->second > p1->second)
					return true;
			}
		}
		else
		{
			if (p1->first > p2->first)
				swap(p1, p2);
			if (p3->first > p4->first)
				swap(p3, p4);

			if (p1->first < p3->first)
			{
				if (p2->first > p3->first)
					return true;
			}
			else
			{
				if (p4->first > p1->first)
					return true;
			}
		}

		return false;
	}

private:
	vector<Pos> mPoses1, mPoses2;
	int mN, mM;

};

void Solve()
{
	int T;
	cin >> T;

	while (T--)
	{
		Q ans;
		ans.Solve();
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}