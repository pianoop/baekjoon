//철로
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Data
{

	int dist, L, R;
};

class Q
{
public:
	Q()
	{
		input();;
	}

	void Solve()
	{
		bool prevS = false;
		int prev = 0x7FFFFFFF, cnt = 0, ans= 0;

		for (auto [x, sign] : mPoses)
		{
			bool flag = sign < 0;
			if (flag)
				cnt++;

			ans = max(ans, cnt);

			if (!flag)
				cnt--;
		}

		cout << ans;
	}


private:
	void input()
	{
		int n;
		cin >> n;

		vector<Data> Datas(n);
		for (auto& [d, l, r] : Datas)
		{
			cin >> l >> r;
			if (l > r)
				swap(l, r);

			d = r - l;
		}

		cin >> mL;

		mPoses.reserve(n);
		for (auto& [d, l, r] : Datas)
		{
			if (d > mL)
				continue;

			mPoses.push_back({ l, 0 });
			mPoses.push_back({ r - mL , -1});
		}
		
		sort(mPoses.begin(), mPoses.end());
	}



private:
	vpii mPoses;
	int mL;
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