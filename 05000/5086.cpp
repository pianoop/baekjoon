//배수와 약수
//-------------------------------------------------------------------
#include <iostream>

int main()
{
	int a, b;
	std::string s[3]{ "factor","multiple","neither" };

	while (scanf("%d%d", &a, &b))
	{
		if (a == 0 && b == 0)
			break;

		if (b % a == 0)
			std::cout << s[0] << "\n";
		else if (a % b == 0)
			std::cout << s[1] << "\n";
		else
			std::cout << s[2] << "\n";
	}

	return 0;
}