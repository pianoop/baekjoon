//차량 번호판 1
//-------------------------------------------------------------------
#include <iostream>


void Solve()
{
	std::string str;
	std::cin >> str;

	bool mPrevState = str[0] == 'c' ? true : false;
	int ans = 1;

	for (auto c : str)
	{
		if (c == 'd')
		{
			if (mPrevState)
				ans *= 9;
			else
			{
				ans *= 10;
				mPrevState = true;
			}
		}
		else
		{
			if (!mPrevState)
				ans *= 25;
			else
			{
				ans *= 26;
				mPrevState = false;
			}
		}
	}

	std::cout << ans;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}