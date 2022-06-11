//방법을 출력하지 않는 숫자 맞추기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<char> vc;

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int* prev = new int[10], * now = new int[10];

		int L, R, k;

		for (int i = 0; i < 10; i++)
			prev[i] = i;

		for (int i = 0; i < mN; i++)
		{
			R = mStart[i] - mFin[i];
			if (R < 0)
				R += 10;

			if (R == 0)
				L = 0;
			else
				L = 10 - R;

			k = L;

			for (int j = 0; j < 10; j++)
			{
				now[j] = prev[j] + R;

				R++;
				if (R > 9)
					R -= 10;
			}

			for (int j = 0; j < 10; j++)
			{
				now[k] = std::min(now[k], prev[j] + L);

				if (--L < 0)
					L += 10;
			}

			std::swap(prev, now);
		}

		int ans = prev[0];
		for (int i = 1; i < 10; i++)
			ans = std::min(ans, prev[i]);

		std::cout << ans;
	}


private:
	void input()
	{
		std::cin >> mN;
		mStart.resize(mN);
		mFin.resize(mN);

		for (auto& c : mStart)
			std::cin >> c;
		for (auto& c : mFin)
			std::cin >> c;
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