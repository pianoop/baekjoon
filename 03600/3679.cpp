//단순 다각형
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

struct Pos
{
	int y = 0, x = 0, Dx = 0, Dy = 0, idx = 0;
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
		for (auto& i : mPoses)
			cout << i.idx << " ";
		cout << "\n";
	}


private:
	void input()
	{
		std::cin >> mN;
		mPoses.resize(mN);
		int order = 0;
		for (auto& [y, x, dx, dy, idx] : mPoses)
		{
			cin >> x >> y;
			idx = order++;
		}

		sort(mPoses.begin(), mPoses.end(), [](Pos& One, Pos& Other) -> bool
			{
				if (One.y == Other.y)
					return One.x < Other.x;
				return One.y < Other.y;
			});

		int x0 = mPoses[0].x, y0 = mPoses[0].y;
		for (auto& [y, x, dx, dy, idx] : mPoses)
		{
			dx = x - x0;
			dy = y - y0;
		}

		//ccw = 0인 구간은 모두 이전 ccw가 음수일 경우로 처리, 이후 Solve()에서 양수인 부분 예외처리
		sort(mPoses.begin() + 1, mPoses.end(), [](Pos& One, Pos& Other) -> bool
			{
				int L = One.Dy * Other.Dx, R = One.Dx * Other.Dy;
				if (L == R)
				{
					if (One.y == Other.y)
						return One.x < Other.x;
					return One.y > Other.y;
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
				return One.y < Other.y;
			});
	}

	inline int ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		return (a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y);
	}

	inline bool sameAngle(const Pos& One, const Pos& Other)
	{
		int L = One.Dy * Other.Dx, R = One.Dx * Other.Dy;
		return L == R;
	}


private:
	vector<Pos> mPoses;
	int mN, mR;

};

void Solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		Q q;
		q.Solve();
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}