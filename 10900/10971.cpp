//외판원 순회 2
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		for (int i = 0; i < mN; i++)
			recur(i, 1, 0, i);

		std::cout << ans;
	}

private:
	void input()
	{
		memset(mCheck, false, sizeof(mCheck));

		std::cin >> mN;
		mArr.resize(mN, vi(mN));

		for (auto& ii : mArr)
			for (auto& i : ii)
				std::cin >> i;
	}

	void recur(int now, int cnt, int tot, const int S)
	{
		if (cnt == mN)
		{
			if(mArr[now][S] != 0)
				ans = std::min(tot + mArr[now][S], ans);

			return;
		}

		cnt++;
		mCheck[now] = true;
		for (int i = 0; i < mN; i++)
		{
			if(!mCheck[i] && mArr[now][i] != 0)
				recur(i, cnt, tot + mArr[now][i], S);
		}
		mCheck[now] = false;
	}

private:
	std::vector<vi> mArr;
	int mN, ans = 0x7FFFFFFF;
	bool mCheck[10];
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