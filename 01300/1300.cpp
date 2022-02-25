//K번째 수
//-------------------------------------------------------------------
#include <iostream>

template<typename T>
T Min(const T& a, const T& b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	int left = 1, right = N>31623?1000000000:N * N;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		int temp = 0;
		for (int i = 1;i <= N;i++)
		{
			temp += Min(N, mid / i);
		}
		if (temp < K)
			left = mid + 1;
		else
			right = mid - 1;
	}
	std::cout << left;

	return 0;
}

