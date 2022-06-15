//-------------------------------------------------------------------
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<char> vc;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		vvi dp(mN + 1, vi(10));
		vi subL(mN + 1), subR(mN + 1);
		int L, R, k, prev = 0;

		for (int i = 1; i < 10; i++)
			dp[0][i] = i;

		for (int i = 1; i <= mN; i++)
		{
			R = mStart[i] - mFin[i];
			if (R < 0)
				R += 10;

			if (R == 0)
				L = 0;
			else
				L = 10 - R;

			subR[i] = R;
			subL[i] = k = L;

			for (int j = 0; j < 10; j++)
			{
				dp[i][j] = dp[prev][j] + R;

				R++;
				if (R > 9)
					R -= 10;
			}

			for (int j = 0; j < 10; j++)
			{
				dp[i][k] = std::min(dp[i][k], dp[prev][j] + L);

				if (--L < 0)
					L += 10;
			}

			prev = i;
		}

		int ans = dp[mN][0], t0 = 0;
		for (int i = 1; i < 10; i++)
		{
			if (ans > dp[mN][i])
			{
				t0 = i;
				ans = dp[mN][i];
			}
		}

		std::cout << ans << "\n";

		vi trace(mN + 1);
		int calc;
		for (int i = mN; i > 1; )
		{
			prev = i--;
			R = (subR[prev] + t0) % 10;
			calc = ans - R;
			if (calc == dp[i][t0])
				trace[prev] = -R;
			else
			{
				L = subL[prev];
				for (int j = 0; j < 10; j++)
				{
					calc = ans - L;
					if (calc == dp[i][j])
					{
						t0 = j;
						trace[prev] = L;
						break;
					}

					if (--L < 0)
						L += 10;
				}
			}

			ans = calc;
		}
		if (ans == subL[1])
			trace[1] = subL[1];
		else
			trace[1] = -subR[1];

		for (int i = 1; i <= mN; i++)
			std::cout << i << " " << trace[i] << "\n";
	}


private:
	void input()
	{
		std::cin >> mN;
		mStart.resize(mN + 1);
		mFin.resize(mN + 1);

		for (int i = 1; i <= mN; i++)
			std::cin >> mStart[i];
		for (int i = 1; i <= mN; i++)
			std::cin >> mFin[i];
	}


private:
	vc mStart, mFin;
	int mN;

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