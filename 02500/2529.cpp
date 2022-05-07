//부등호
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

class Temp
{
public:
	Temp(int n):mN(n)
	{
		input();
		solve();
	}

	~Temp()
	{
		delete[] mbSign;
	}

private:
	void input()
	{
		mAns.resize(mN + 1);
		mbSign = new bool[mN + 1]();
		mbSign[0] = false;

		bool bCheck[10] = { false, };
		char tmp;
		for (int i = 1; i <= mN; i++)
		{
			std::cin >> tmp;
			if (tmp == '>')
				mbSign[i] = true;
		}

	}
	
	void solve()
	{
		recurMax(0, -1);

		mbEnd = false;
		memset(mbCheck, false, sizeof(bool) * 10);

		recurMin(0, -1);
	}

	void recurMax(int now, int prevNum)
	{
		if (now > mN)
		{
			for (auto ans : mAns)
				std::cout << ans;
			std::cout << "\n";

			mbEnd = true;
			return;
		}

		if (mbSign[now])
		{
			for (int i = 9; i >= 0; i--)
			{
				if (!mbCheck[i] && prevNum > i)
				{
					mbCheck[i] = true;
					mAns[now] = i;
					recurMax(now + 1, i);

					if (mbEnd)
						return;
					mbCheck[i] = false;
				}
			}
		}
		else
		{
			for (int i = 9; i >= 0; i--)
			{
				if (!mbCheck[i] && prevNum < i)
				{
					mbCheck[i] = true;
					mAns[now] = i;
					recurMax(now + 1, i);

					if (mbEnd)
						return;
					mbCheck[i] = false;
				}
			}
		}
	}
	
	void recurMin(int now, int prevNum)
	{
		if (now > mN)
		{
			for (auto ans : mAns)
				std::cout << ans;
			std::cout << "\n";

			mbEnd = true;
			return;
		}

		if (mbSign[now])
		{
			for (int i = 0; i < 10; i++)
			{
				if (!mbCheck[i] && prevNum > i)
				{
					mbCheck[i] = true;
					mAns[now] = i;
					recurMin(now + 1, i);

					if (mbEnd)
						return;
					mbCheck[i] = false;
				}
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				if (!mbCheck[i] && prevNum < i)
				{
					mbCheck[i] = true;
					mAns[now] = i;
					recurMin(now + 1, i);

					if (mbEnd)
						return;
					mbCheck[i] = false;
				}
			}
		}
	}


private:
	vi mAns;
	bool *mbSign, mbCheck[10]={false, };
	int mN;
	bool mbEnd = false;

};

void Solve()
{
	int n;
	std::cin >> n;

	Temp Q(n);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}