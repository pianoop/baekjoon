//내려가기
//-------------------------------------------------------------------
#include <iostream>
#include <array>
typedef std::array<int, 3> ai;

int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;
	
	ai min{ 0 }, max{ 0 };
	{
		ai temp, copytemp;
		for (int i = 0;i < N;i++)
		{
			std::cin >> temp[0] >> temp[1] >> temp[2];
			copytemp[0] = temp[0] + Min(min[0], min[1]);
			copytemp[1] = temp[1] + Min(Min(min[0], min[1]), min[2]);
			copytemp[2] = temp[2] + Min(min[1], min[2]);
			min = copytemp;
			copytemp[0] = temp[0] + Max(max[0], max[1]);
			copytemp[1] = temp[1] + Max(Max(max[0], max[1]), max[2]);
			copytemp[2] = temp[2] + Max(max[1], max[2]);
			max = copytemp;
		}
	}
	std::cout << Max(Max(max[0], max[1]), max[2]) << " " << Min(Min(min[0], min[1]), min[2]);

	return 0;
}