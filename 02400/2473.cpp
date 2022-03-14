//세 용액
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef long long ll;

class Solutions
{
public:
	Solutions()
	{
		Input();
	}

	void PrintAns()
	{
		printf("%d %d %d", mans1, mans2, mans3);
	}

	void Calc()
	{
		int n = int(mSol.size());
		for (int i = 0; i < n - 2; i++)
		{
			int left = i + 1, right = n - 1;
			while (left != right)
			{
				ll sum = ll(mSol[i]) + mSol[left] + mSol[right];

				if (mSum > std::abs(sum))
				{
					mans1 = mSol[i], mans2 = mSol[left], mans3 = mSol[right];
					mSum = std::abs(sum);
				}

				if (sum < 0)
					left++;
				else
					right--;
			}
		}
	}
	
private:
	void Input()
	{
		int N;
		std::cin >> N;
		mSol.resize(N);
		for (auto& a : mSol)
		{
			std::cin >> a;
		}
		std::sort(mSol.begin(), mSol.end());
	}

private:
	vi mSol;
	int mans1 = 0, mans2 = 0, mans3 = 0;
	ll mSum = ll(3'000'000'001);
};

void Solve()
{
	Solutions sol;
	sol.Calc();
	sol.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}