//히스토그램에서 가장 큰 직사각형
//-stack 풀이
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
typedef long long ll;

int main()
{
	int n;

	while (scanf("%d", &n) && n != 0)
	{
		ll MaxS = 0;
		std::stack<int> st1, st1order;
		st1order.push(-1);
		for (int x, i = 0;i < n;i++)
		{
			scanf("%d", &x);
			while (!st1.empty() && x < st1.top())
			{
				st1order.pop();
				if (MaxS < (ll(st1.top()) * (i - st1order.top()-1)))
				{
					MaxS = ll(st1.top()) * (i - st1order.top()-1);
				}
				st1.pop();
			}
			st1.push(x);
			st1order.push(i);
		}
		while (!st1.empty())
		{
			st1order.pop();
			if (MaxS < (ll(st1.top()) * (n - st1order.top() - 1)))
			{
				MaxS = ll(st1.top()) * (n - st1order.top() - 1);
			}
			st1.pop();
		}
		printf("%lld\n", MaxS);
	}

	return 0;
}