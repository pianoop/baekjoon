//Dance Dance Revolution
//-------------------------------------------------------------------
#include <iostream>
#include <array>
typedef std::array<int, 5> ai;
typedef std::array<ai, 5> aai;

void Solve()
{
	const int Max = int(1e9);
	int move[5][5] = { {0,2,2,2,2},{0,1,3,4,3},{0,3,1,3,4},{0,4,3,1,3},{0,3,4,3,1} };

	int foot, last =0;
	aai* pDP1 = new aai;  //pro
	for (auto& a : *pDP1)
		a.fill(Max); 
	aai* pDP2; //post

	std::cin >> foot;
	if (foot == 0)
	{
		printf("0");
		return;
	}
	(*pDP1)[0][foot] = 2;

	while (true)
	{
		std::cin >> foot;
		if (foot == 0)
			break;

		pDP2 = new aai;
		for(auto& a:*pDP2)
			a.fill(Max);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 1; j < 5; j++)
			{
				if ((*pDP1)[i][j] != Max)
					(*pDP2)[i][foot] = std::min((*pDP2)[i][foot], (*pDP1)[i][j] + move[j][foot]);
			}
		}

		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if ((*pDP1)[j][i] != Max)
					(*pDP2)[foot][i] = std::min((*pDP2)[foot][i], (*pDP1)[j][i] + move[j][foot]);
			}
		}

		std::swap(pDP1, pDP2);
		delete pDP2;
		last = foot;
	}

	int ans = Max;
	for (auto& a : *pDP1)
	{
		for (auto& b : a)
			ans = std::min(ans, b);
	}

	printf("%d", ans);

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}