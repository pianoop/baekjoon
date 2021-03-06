//이중 우선순위 큐
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <map>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	
	while (T--)
	{
		int N;
		std::cin >> N;

		std::map<int, int> doublePQ;

		int x, size = 0;
		char c;
		while (N--)
		{
			std::cin >> c >> x;
			if (c == 'I')
			{
				size++;
				doublePQ[x]++;
			}
			else if(size!=0)
			{
				size--;
				if (x == 1)
				{
					auto iter = --doublePQ.end();
					if (iter->second == 1)
						doublePQ.erase(iter);
					else
						(iter->second)--;
				}
				else
				{
					auto iter = doublePQ.begin();
					if (iter->second == 1)
						doublePQ.erase(iter);
					else
						(iter->second)--;
				}

			}
			if (size == 0)
			{
				doublePQ = {};
			}
		}
		if (size == 0)
			std::cout << "EMPTY\n";
		else
			std::cout << (--doublePQ.end())->first << " " << (doublePQ.begin())->first  <<"\n";
	}

	return 0;
}