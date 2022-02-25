//blobblush
//-------------------------------------------------------------------
#include <iostream>
typedef long long ll;

int main()
{
	ll n;
	std::cin >> n;

	ll twopow = 1;
	for (;twopow <= n;twopow = twopow << 1);
	if (twopow - 1 == n)
	{
		std::cout << 1 << "\n" << twopow - 1;
	}
	else
	{
		std::cout << 2 << "\n" << twopow - n - 1 << " " << n;
	}

	return 0;
}