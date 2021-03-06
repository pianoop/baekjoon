//검문
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int GCD(const int& fA, const int& fB)
{
	int r = fA % fB;
	if (r == 0)
		return fB;
	return GCD(fB, r);
}

int main()
{
	int N;
	scanf("%d", &N);

	int A,B, gcd;
	scanf("%d%d", &A,&B);
	gcd = abs(A - B);
	for (int i = 2;i < N;i++)
	{
		scanf("%d", &A);
		gcd=GCD(gcd, abs(A - B));
		B = A;
	}
	
	std::queue<int> qgcd;
	std::stack<int> sgcd;
	int i;
	sgcd.push(gcd);
	for (i = 2;i*i <gcd ;i++)
	{
		if (gcd % i == 0)
		{
			qgcd.push(i);
			sgcd.push(gcd / i);
		}
	}
	if (i * i == gcd)
		qgcd.push(i);
	
	while (!qgcd.empty())
	{
		printf("%d ", qgcd.front());
		qgcd.pop();
	}

	while (!sgcd.empty())
	{
		printf("%d ", sgcd.top());
		sgcd.pop();
	}

	return 0;
}