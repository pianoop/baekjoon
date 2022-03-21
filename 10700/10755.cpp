//공항
//-------------------------------------------------------------------
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <iostream>
#include <vector>
#include <cstring>
typedef std::vector<int> vi;

void Solve()
{
	int numGate, numAir;
	std::cin >> numGate >> numAir;

	vi gate(numGate + 1);

	bool endflag = false;
	int nowAir, ans = 0;
	while (numAir--)
	{
		std::cin >> nowAir;
		int nowgate = nowAir;
		
		while (true)
		{
			if (nowgate == 0)
			{
				endflag = true;
				break;
			}
			else if (gate[nowgate] == 0)
			{
				break;
			}
			else
			{
				nowgate = gate[nowgate] - 1;
			}

		}

		if (endflag)
		{
			while (std::cin >> nowgate)	{}
			break;
		}
		gate[nowAir] = nowgate;
		gate[nowgate] = nowgate;
		
		ans++;
	}

	printf("%d", ans);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();
	
	return 0;
}