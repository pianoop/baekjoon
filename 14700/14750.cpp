//Jerry and Tom
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INTMAX = 0x7FFFFFFF;

class Pos
{
public:
	int x, y;

	bool operator==(Pos& Other)
	{
		return x == Other.x && y == Other.y;
	}
};
typedef vector<Pos> vP;

class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int cnt = 0;

		while (true)
		{
			int tmp = bfs();
			if (tmp == 0)
				break;

			cnt += tmp;
		}

		if (cnt == mM)
			cout << "Possible";
		else
			cout << "Impossible";
	}


private:
	void init()
	{
		cin >> mN >> mK >> mH >> mM;
		mSize = mM + mH + 2;

		mEdges.resize(mSize);
		mCap.resize(mSize, vi(mSize));
		mFlow.resize(mSize, vi(mSize));


		vP corners(mN), holes(mH);

		for (auto& [x, y] : corners)
			cin >> x >> y;
		corners.push_back(corners.front());

		for (auto& [x, y] : holes)
			cin >> x >> y;

		int idxStart = mM + 1;
		Pos mouse;
		for (int i = 1; i <= mM; i++)
		{
			cin >> mouse.x >> mouse.y;

			int idxH = idxStart;
			for (auto& posH : holes)
			{
				if (!cross(mouse, posH, corners))
				{
					mEdges[i].push_back(idxH);
					mEdges[idxH].push_back(i);
					mCap[i][idxH] = 1;
				}

				idxH++;
			}
		}

		mS = 0, mD = mSize - 1;

		for (int i = 1; i <= mM; i++)
		{
			mEdges[0].push_back(i);
			mEdges[i].push_back(0);
			mCap[0][i] = 1;
		}

		for (int i = idxStart; i < mD; i++)
		{
			mEdges[i].push_back(mD);
			mCap[i][mD] = mK;
		}
	}

	int bfs()
	{
		bool bEndFlag = false;

		vi Trace(mSize, -1);
		queue<int> box;
		box.push(mS);

		while (!box.empty())
		{
			int now = box.front();
			box.pop();

			for (auto next : mEdges[now])
			{
				if (Trace[next] < 0 && mCap[now][next] - mFlow[now][next] > 0)
				{
					box.push(next);
					Trace[next] = now;

					if (next == mD)
					{
						bEndFlag = true;
						break;
					}
				}
			}

			if (bEndFlag)
				break;
		}

		if (Trace[mD] < 0)
			return 0;

		int flow = INTMAX;
		for (int i = mD; i != mS; i = Trace[i])
			flow = min(flow, mCap[Trace[i]][i] - mFlow[Trace[i]][i]);
		for (int i = mD; i != mS; i = Trace[i])
		{
			mFlow[Trace[i]][i] += flow;
			mFlow[i][Trace[i]] -= flow;
		}

		return flow;
	}

	inline bool cross(Pos& mouse, Pos& hole, vP& corners)
	{
		int cnt = 0;
		for (int i = 0; i < mN;)
		{
			auto& dot1 = corners[i++];
			auto& dot2 = corners[i];
			if (dot1 == hole)
				continue;

			int a = ccw(mouse, hole, dot1) * ccw(mouse, hole, dot2),
				b = ccw(dot1, dot2, hole) * ccw(dot1, dot2, mouse);

			if (a <= 0 && b <= 0)
			{
				if (a == 0 && b == 0)
				{
					if (ccwException(&mouse, &hole, &dot1, &dot2))
						cnt++;
				}
				else
					cnt++;
			}
		}

		if (cnt < 2)
			return false;
		else
			return true;
	}

	inline int ccw(const Pos& a, const Pos& b, const Pos& c)
	{
		ll tmp = ll(a.x - b.x) * (a.y - c.y) - ll(a.x - c.x) * (a.y - b.y);
		return tmp < 0 ? -1 : (tmp > 0 ? 1 : 0);
	}

	inline bool ccwException(Pos* mouse, Pos* hole, Pos* dot1, Pos* dot2)
	{
		if (mouse->x == hole->x)
		{
			if (mouse->y > hole->y)
				swap(mouse, hole);
			if (dot1->y > dot2->y)
				swap(dot1, dot2);

			if (mouse->y < dot1->y)
			{
				if (hole->y > dot1->y)
					return true;
			}
			else
			{
				if (dot2->y > mouse->y)
					return true;
			}
		}
		else if (mouse->y == hole->y)
		{
			if (mouse->x > hole->x)
				swap(mouse, hole);
			if (dot1->x > dot2->x)
				swap(dot1, dot2);

			if (mouse->x < dot1->x)
			{
				if (hole->x > dot1->x)
					return true;
			}
			else
			{
				if (dot2->x > mouse->x)
					return true;
			}
		}

		return false;
	}

private:
	vvi mEdges, mCap, mFlow;
	int mSize, mN, mM, mH, mS, mD, mK;

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