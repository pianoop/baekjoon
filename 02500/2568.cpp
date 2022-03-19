//전깃줄 - 2
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

class UtilityPole
{
public:
	UtilityPole()
	{
		input();
	}

	void PrintAns()
	{
		calc();
		printf("%d\n", int(mAns.size()));
		for (auto& a : mAns)
			printf("%d\n", a);
	}

private:
	void input()
	{
		int n;
		std::cin >> n;
		mAns.reserve(n);
		mPole.resize(n);
		for (auto& [a, b] : mPole)
			std::cin >> a >> b;

		std::sort(mPole.begin(), mPole.end(), [](pi& A, pi& B)->bool
			{
				return A.first < B.first;
			});
	}

	void calc()
	{
		std::vector<pi> boundtable;
		boundtable.reserve(int(mPole.size() + 1));
		vvi tracking(int(mPole.size()+1));

		boundtable.push_back({ 0,0 });
		for (auto& line : mPole)
		{
			if (boundtable.back().second < line.second)
			{
				tracking[boundtable.size()].push_back(line.first);
				boundtable.push_back(line);
			}
			else
			{
				auto iter = std::upper_bound(boundtable.begin(), boundtable.end(), line
					, [](const pi& a, const pi& b)->bool {return a.second < b.second; });
				*iter = line;

				tracking[iter-boundtable.begin()].push_back(line.first);
			}
		}
		int now = 1'000'000;
		for (auto iterN = tracking.rbegin(); iterN != tracking.rend(); ++iterN)
		{
			auto iterM = iterN->rbegin();
			for (; iterM != iterN->rend(); ++iterM)
			{
				if (now > *iterM )
				{
					now = *iterM;
					++iterM;
					break;
				}
				mAns.push_back(*iterM);
			}

			for (; iterM != iterN->rend(); ++iterM)
			{
				mAns.push_back(*iterM);
			}
		}
		std::sort(mAns.begin(), mAns.end());
	}

private:
	std::vector<pi> mPole;
	vi mAns;
};

void Solve()
{
	UtilityPole pole;
	pole.PrintAns();

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}