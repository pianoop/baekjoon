//Mowing the Lawn
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
		int right = mN + mD - 1;
		dq.push_back({ mN, 0 });

		ll nowData;
		for (int i = mN - 1; i >= 0; i--, right--)
		{
			while (dq.front().first > right)
				dq.pop_front();

			nowData = mData[i] + dq.front().second;

			while (!dq.empty() && dq.back().second >= nowData)
				dq.pop_back();

			dq.push_back({ i, nowData });
		}

		while (dq.front().first > right)
			dq.pop_front();

		std::cout << mTot - dq.front().second;
	}


private:
	void input()
	{
		std::cin >> mN >> mD;
		mD++;
		mData.resize(mN);
		for (auto& i : mData)
		{
			std::cin >> i;
			mTot += i;
		}
	}


private:
	vi mData;
	ll mTot = 0;
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