//연세워터파크
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <deque>
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int, ll> pil;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		std::deque<pil> dq;
		ll ans = mData[0];
		int right = mN + mD - 2;
		dq.push_back({ mN - 1, mData[mN - 1] });

		ll nowData;
		for (int i = mN - 2; i >= 0; i--, right--)
		{
			while (dq.back().first > right)
				dq.pop_back();

			nowData = mData[i];
			nowData = std::max(nowData, nowData + dq.back().second);
			ans = std::max(ans, nowData);

			while (!dq.empty() && dq.front().second <= nowData)
				dq.pop_front();
			
			dq.push_front({i, nowData});
		}


		std::cout << ans;
	}


private:
	void input()
	{
		std::cin >> mN >> mD;
		mData.resize(mN);
		for (auto& i : mData)
			std::cin >> i;
	}


private:
	vi mData;
	int mN, mD;

};

void Solve()
{
	Q q;
	q.Solve();
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}