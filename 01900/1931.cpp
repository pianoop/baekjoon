//회의실 배정
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<std::pair<int, int> > vpi1;

	for (int x, y, i = 0;i < N;i++)
	{
		scanf("%d%d", &x, &y);
		vpi1.push_back({ y,x });
	}
	std::sort(vpi1.begin(), vpi1.end());

	int h = 0, m = 0;
	for (int i = 0;i < N;i++)
	{
		if (h <= vpi1[i].second)
		{
			m++;
			h = vpi1[i].first;
		}
	}
	printf("%d", m);

	return 0;
}