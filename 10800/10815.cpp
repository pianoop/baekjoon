//숫자 카드
//-------------------------------------------------------------------
#include <iostream>
#include <set>

void Solve()
{
	std::set<int> card;
	int N;
	std::cin >> N;

	int tmp;
	while (N--)
	{
		std::cin >> tmp;
		card.insert(tmp);
	}

	std::cin >> N;
	while (N--)
	{
		std::cin >> tmp;
		if (card.find(tmp) == card.end())
			std::cout << "0 ";
		else
			std::cout << "1 ";
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}