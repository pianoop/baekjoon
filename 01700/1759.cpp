//암호 만들기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<char, bool> pcb;
typedef std::vector<char> vc;

class Passwd
{
public:
	Passwd()
	{
		input();
		solve();
	}

private:
	void input()
	{
		std::cin >> mM >> mN;
		mAns.resize(mM);
		mC.resize(mN);
		for (auto& [a,b]:mC)
		{
			std::cin >> a;
			if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
				b = true;
			else
				b = false;
		}

		std::sort(mC.begin(), mC.end(), [](pcb& a, pcb& b)->bool
			{
				return a.first < b.first;
			});
	}

	void solve()
	{
		recur(0, 0, false, false, false);
	}

	void recur(int i, int now, bool a, bool b, bool c)
	{
		if (now == mM)
		{
			if (a && b)
			{
				for (char c : mAns)
					std::cout << c;
				std::cout << "\n";
			}

			return;
		}

		int next = now + 1;
		for (; i < mN; i++)
		{
			auto [C,B] = mC[i];
			mAns[now] = C;
			if (!a || !b)
			{
				if (B)
					recur(i + 1, next, true, b, c);
				else
				{
					if (!c)
						recur(i + 1, next, a, b, true);
					else
						recur(i + 1, next, a, true, c);
				}
			}
			else
				recur(i + 1, next, a, b, c);
		}
	}

private:
	std::vector<pcb> mC;
	vc mAns;
	int mN, mM;

};

void Solve()
{
	Passwd passwd;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}