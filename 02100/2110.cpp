//공유기 설치
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, C;
	std::cin >> N >> C;
	C--;
	std::vector<int> vi(N);
	for (int i = 0;i < N;i++)
		std::cin >> vi[i];
	
	std::sort(vi.begin(), vi.end());
	int left = 0, right = vi[N - 1]- vi[0];
	for (int i=0;i<N-1;i++)
		vi[i] = vi[i + 1] - vi[i];
	vi.pop_back();

	int mid = (right + left) / C;
	while (left <= right)
	{
		int num = 0, temp = 0;
		for (auto i : vi)
		{
			num += i;
			if (mid <= num)
			{
				num = 0;
				temp++;
			}
		}
		if (temp >= C)
			left = mid+1;
		else
			right = mid-1;
		mid = (right + left) / 2;
	}
	std::cout << right;

	return 0;
}