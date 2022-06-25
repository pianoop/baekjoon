//Convex Hull
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
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
		input();
	}

	void Solve()
	{
		cout << mN << "\n";
		for (int i = 0; i < mN; i++)
			cout << mPoses[i].x << " " << mPoses[i].y << "\n";
	}


private:
	void input()
	{
		cin >> mN;

		mPoses.reserve(mN);
		int x, y;
		char c;
		for (int i = 0; i < mN; i++)
		{
			cin >> x >> y >> c;
			if (c == 'Y')
				mPoses.push_back({ x, y, 0, 0 });
		}
		mN = (int)mPoses.size();

		sort(mPoses.begin(), mPoses.end(), [](Pos& One, Pos& Other) -> bool
			{
				if (One.x == Other.x)
					return One.y < Other.y;
				return One.x < Other.x;
			});

		int x0 = mPoses[0].x, y0 = mPoses[0].y;
		for (auto& [x, y, dx, dy] : mPoses)
		{
			dx = x - x0;
			dy = y - y0;
		}

		sort(mPoses.begin() + 1, mPoses.end(), [](Pos& One, Pos& Other) -> bool
			{
				ll L = ll(One.Dy) * Other.Dx, R = ll(One.Dx) * Other.Dy;
				if (L == R)
				{
					if (One.x == Other.x)
						return One.y > Other.y;
					return One.x > Other.x;
				}

				return L < R;
			});

		int e = mN;
		for (int i = 1; i < mN; i++)
		{
			if (!sameAngle(mPoses[i], mPoses[i + 1]))
			{
				e = i + 1;
				break;
			}
		}

		sort(mPoses.begin() + 1, mPoses.begin() + e, [](Pos& One, Pos& Other) -> bool
			{
				return One.x < Other.x;
			});
	}

	inline bool sameAngle(const Pos& One, const Pos& Other)
	{
		int L = One.Dy * Other.Dx, R = One.Dx * Other.Dy;
		return L == R;
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