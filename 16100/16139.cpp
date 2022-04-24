//인간-컴퓨터 상호작용
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Strnum
{
public:
	Strnum()
	{
		input();
	}

	void Query()
	{
		int n;
		std::cin >> n;

		char a;
		int l, r;
		while (n--)
		{
			std::cin >> a >> l >> r;
			int now = a - 97;
			std::cout << (mAns[now][r] - (l == 0 ? 0 : mAns[now][l - 1])) << "\n";
		}
	}

private:
	void input()
	{
		std::string str;
		std::cin >> str;
		mAns.resize(26, vi(int(str.length())));

		int last[26] = {0,};
		for (int i= 0; i<int(str.length());i++)
		{
			int now = str[i] - 97;
			mAns[now][i] = mAns[now][last[now]] + 1;
			last[now] = i;
		}

		for (auto& alph : mAns)
		{
			int prev = 0;
			for (auto& num : alph)
			{
				if (num == 0)
					num = prev;
				else
					prev = num;
			}
		}
	}

private:
	std::vector<vi> mAns;

};

void Solve()
{
	Strnum str;
	str.Query();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();


	return 0;
}