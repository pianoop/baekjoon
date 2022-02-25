//가운데를 말해요
//-------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::priority_queue<int> max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

	int x;
	std::cin >> x;
	int Med = x;
	std::cout << Med<<"\n";

	while (--N)
	{
		std::cin >> x;
		if (max_heap.size() < min_heap.size())
		{
			if (Med > x)
				max_heap.push(x);
			else
			{
				max_heap.push(Med);
				Med = x;
			}
		}
		else
		{
			if (Med < x)
				min_heap.push(x);
			else
			{
				min_heap.push(Med);
				Med = x;
			}
		}
		if (!min_heap.empty() && !max_heap.empty())
		{
			while (Med > min_heap.top() || Med < max_heap.top())
			{
				if (Med > min_heap.top())
				{
					int temp = min_heap.top();
					min_heap.pop();
					min_heap.push(Med);
					Med = temp;
				}
				else
				{
					int temp = max_heap.top();
					max_heap.pop();
					max_heap.push(Med);
					Med = temp;
				}
			}
		}
		std::cout << Med << "\n";
	}

	return 0;
}
