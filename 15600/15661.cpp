//링크와 스타트
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class SoccerTeam
{
public:
	SoccerTeam()
	{
		input();
		solve();
	}

private:
	void input()
	{
		std::cin >> mN;
		mSyn.resize(mN, vi(mN));
		for (auto& S : mSyn)
			for (auto& s : S)
				std::cin >> s;
	}

	void solve()
	{
		recur(0, 0, 0, 0);

		std::cout << mMin;
	}

	void recur(int now, int t1, int t2, int b1)
	{
		int next = now + 1, tot1 = 0, tot2 = 0, bit = 1;
		for (int i = 0; i < now; i++, bit <<= 1)
		{
			if (bit & b1)
				tot1 += mSyn[i][now] + mSyn[now][i];
			else
				tot2 += mSyn[i][now] + mSyn[now][i];
		}

		if (next == mN)
		{
			mMin = std::min(mMin, std::abs(t1 + tot1 - t2));
			mMin = std::min(mMin, std::abs(t1 - tot2 - t2));
		}
		else
		{
			recur(next, t1 + tot1, t2, b1 | (1 << now));
			recur(next, t1, t2 + tot2, b1);
		}
	}

private:
	int mN, mMin = 1000000;
	vvi mSyn;
};

void Solve()
{
	SoccerTeam soccer;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}