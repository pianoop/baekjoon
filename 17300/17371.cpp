//이사
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int ans, min = 0x7FFFFFFF;
		size_t end = mPoses.size();
		for (size_t i = 0; i < end; i++)
		{
			int dist = maxDistPow(i);
			if (min > dist)
			{
				min = dist;
				ans = i;
			}
		}

		cout << fixed;
		cout.precision(8);
		cout << mPoses[ans].first << " " << mPoses[ans].second;
	}

private:
	void input()
	{
		int n;
		cin >> n;
		mPoses.resize(n);

		for (auto& [x, y] : mPoses)
			cin >> x >> y;
	}

	int maxDistPow(int s)
	{
		int maxDist = 0;
		pii& S = mPoses[s];

		for (auto& D : mPoses)
			maxDist = max(maxDist, dist(S, D));

		return maxDist;
	}

	inline int dist(pii& a, pii& b)
	{
		int dx = a.first - b.first, dy = a.second - b.second;
		return dx * dx + dy * dy;
	}

private:
	vpii mPoses;

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