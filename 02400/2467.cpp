//용액
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

class Solutions
{
public:
	Solutions()
	{
		Input();
	}

	void PrintAns()
	{
		if (n > 0 && m > 0)
		{
			Calc();   //
		}
		if (n > 1)
		{
			Cmpans(neg[n - 2], neg[n - 1]);
		}
		if (m > 1)
		{
			Cmpans(pos[0], pos[1]);
		}

		printf("%d %d", ans1, ans2);
	}

private:
	void Input()
	{
		int N, i = 0;;
		std::cin >> N;

		int temp;
		for (; i < N; i++)
		{
			std::cin >> temp;
			if (temp > 0)  //0은 없음(아마도)
			{
				pos.push_back(temp);
				i++;
				break;
			}
			neg.push_back(temp);
		}
		for (; i < N; i++)
		{
			std::cin >> temp;
			pos.push_back(temp);
		}
		n = int(neg.size());
		m = int(pos.size());
	}

	void Calc()
	{
		int a = n - 1, b = 0;
		Cmpans(neg[a], pos[b]);
		msum = nowsum = std::abs(neg[a] + pos[b]);
		ans1 = neg[a], ans2 = pos[b];
		while (a > 0 && b < m - 1)
		{
			//비교하는 대상은 이전 값, ans가 X

			bool flag1 = bCmpnow(neg[a - 1], pos[b]);
			bool flag2 = bCmpnow(neg[a], pos[b + 1]);

			if (flag2)
			{
				b++;
				if (nowsum < msum)
				{
					msum = nowsum;
					ans1 = neg[a];
					ans2 = pos[b];
				}
			}
			else if (flag1)
			{
				a--;
				if (nowsum < msum)
				{
					msum = nowsum;
					ans1 = neg[a];
					ans2 = pos[b];
				}
			}
			else
			{
				nowsum = std::abs(neg[--a]+ pos[++b]);
				if (nowsum < msum)
				{
					msum = nowsum;
					ans1 = neg[a];
					ans2 = pos[b];
				}
			}
		}

		if (a == 0 && b != m - 1)
		{
			while (b != m - 1)
			{
				if (!bCmpnow(neg[a], pos[++b]))
					break;
			}
			if (b != m - 1)
				b--;
			if (nowsum < msum)
			{
				msum = nowsum;
				ans1 = neg[a];
				ans2 = pos[b];
			}
		}
		else if (b == m - 1 && a != 0)
		{
			while (a != 0)
			{
				if (!bCmpnow(neg[--a], pos[b]))
					break;
			}
			if (a != 0)
				a++;
			if (nowsum < msum)
			{
				msum = nowsum;
				ans1 = neg[a];
				ans2 = pos[b];
			}
		}
	}

	bool bCmpnow(int A, int B)
	{
		if (std::abs(A + B) < nowsum)
		{
			nowsum = std::abs(A + B);
			return 1;
		}
		else
			return 0;
	}

	void Cmpans(int A, int B)
	{
		if (std::abs(A + B) < msum)
		{
			ans1 = A, ans2 = B;
			msum = std::abs(ans1 + ans2);
		}
	}

private:
	vi neg, pos;
	int n, m, ans1 = 0, ans2 = 0, msum = int(2e9) + 1;
	int nowsum;
};

void Solve()
{
	Solutions sol;
	sol.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}