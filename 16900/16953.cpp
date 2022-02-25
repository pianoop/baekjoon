//A → B
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	const int Max = 100'000'001;
	int A, B;
	std::cin >> A >> B;

	std::queue<pii> bfsbox;
	bfsbox.push({ A,1 });

	int ans = 0;
	while (!bfsbox.empty())
	{
		auto now = bfsbox.front();
		bfsbox.pop();
		if (now.first > B)
			continue;
		else if (now.first == B)
		{
			ans = now.second;
			break;
		}

		bfsbox.push({ now.first * 2,now.second + 1 });
		if(now.first<Max)
			bfsbox.push({ now.first * 10 + 1,now.second + 1 });

	}

	if (ans == 0)
		std::cout << "-1";
	else
		std::cout << ans;

	return 0;
}