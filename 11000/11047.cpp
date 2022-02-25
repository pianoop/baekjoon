//동전 0
//-------------------------------------------------------------------
#include <iostream>
#include <stack>

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	std::stack<int> si1;

	for (int x,i = 0;i < N;i++)
	{
		scanf("%d", &x);
		si1.push(x);
	}

	int total = 0;
	while (K)
	{
		total += K / si1.top();
		K %= si1.top();
		si1.pop();
	}
	printf("%d", total);

	return 0;
}