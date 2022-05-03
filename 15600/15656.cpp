//N과 M (7)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

class Temp
{
public:
	Temp()
	{
		input();
		solve();
	}

private:
	void input()
	{
		std::cin >> mN >> mM;

		mArr.resize(mN);
		for (auto& i : mArr)
			std::cin >> i;

		std::sort(mArr.begin(), mArr.end());
	}

	void solve()
	{
		vi ans(mM);
		recur(0, ans);
	}

	void recur(int n, vi& ans)
	{
		if (n == mM)
		{
			for (auto& a : ans)
				std::cout << a << " ";
			std::cout << "\n";
			
			return;
		}

		for (int i = 0; i < mN; i++)
		{
			ans[n] = mArr[i];
			recur(n + 1, ans);
		}
	}

private:
	int mN,mM;
	vi mArr;
};

void Solve()
{
	Temp NM;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}