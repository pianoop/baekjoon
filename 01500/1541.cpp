//잃어버린 괄호
//-------------------------------------------------------------------
#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;

	int total = 0, t = 0, flag = 0;
	for (auto si : s)
	{
		if (si == '+' || si == '-')
		{
			if (flag)
				total -= t;
			else
				total += t;

			if (si == '-')
				flag = 1;
			t = 0;
		}
		else
		{
			t *= 10;
			t += (si - 48);
		}
	}
	if (flag)
		total -= t;
	else
		total += t;

	printf("%d", total);

	return 0;
}