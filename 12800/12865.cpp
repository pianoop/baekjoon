//평범한 배낭
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	std::vector<int> vi1(K + 1, -1);
	vi1[0] = 0;

	int W, V;
	for (int i = 0;i < N;i++)
	{
		scanf("%d%d", &W, &V);
		for (int j = K-1;j >=0 ;j--)
		{
			if (j + W <= K && vi1[j] != -1 && vi1[j + W] < vi1[j] + V)
				vi1[j + W] = vi1[j] + V;
		}
	}
	int Max = 0;
	for (auto v : vi1)
		if (Max < v)
			Max = v;

	printf("%d", Max);

	return 0;
}