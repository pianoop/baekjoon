//수열
//-------------------------------------------------------------------
#include <iostream>
#include <queue>

class Seq
{
public:
	Seq()
	{
		solve();
	}



private:
	void solve()
	{
		int n, k;
		std::cin >> n >> k;

		int i = 0, total = 0, tmp, max;
		for(; i < k; i++)
		{
			std::cin >> tmp;
			total += tmp;
			mWin.emplace(tmp);
		}

		max = total;
		for (; i < n; i++)
		{
			std::cin >> tmp;
			mWin.emplace(tmp);
			total = total + tmp - mWin.front();
			mWin.pop();

			if (total > max)
				max = total;
		}

		std::cout << max;
	}


private:
	std::queue<int> mWin;

};

void Solve()
{
	Seq seq;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}