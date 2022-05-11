//에너지 모으기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

class Energy
{
public:
	Energy()
	{
		input();
		solve();
	}


private:
	void input()
	{
		memset(mbCheck, false, sizeof(mbCheck));
		std::cin >> mN;
		mEnergy.resize(mN);
		for (auto& E : mEnergy)
			std::cin >> E;
		mN--;					 //주의
	}

	void solve()
	{
		recur(mN - 1, 0);
		std::cout << mAns;
	}

	void recur(int now, int total)
	{
		if (now == 0)
		{
			mAns = std::max(mAns, total);
			return;
		}

		now--;
		for (int i = 1; i < mN; i++)
		{
			if (!mbCheck[i])
			{
				mbCheck[i] = true;

				int tmp = i - 1, tot;
				while (mbCheck[tmp])
					tmp--;
				tot= mEnergy[tmp];

				tmp = i + 1;
				while (mbCheck[tmp])
					tmp++;
				
				recur(now, total + tot * mEnergy[tmp]);

				mbCheck[i] = false;
			}
		}
	}

private:
	vi	mEnergy;
	bool mbCheck[10];
	int mN, mAns = 0;

};

void Solve()
{
	Energy drain;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}