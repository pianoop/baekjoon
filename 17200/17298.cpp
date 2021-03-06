//오큰수
//-------------------------------------------------------------------
#include <iostream>
#include <stack>

int main()
{
	int N;
	scanf("%d", &N);

	int x;
	std::stack<int> stacki1;
	while (N--)
	{
		scanf("%d", &x);
		stacki1.push(x);
	}

	std::stack<int> stacki2, stacki3;
	stacki2.push(0);
	while (!stacki1.empty())
	{
		if (stacki1.top() < stacki2.top())
		{
			stacki3.push(stacki2.top());
			stacki2.push(stacki1.top());
			stacki1.pop();
		}
		else
		{
			stacki2.pop();
			if (stacki2.empty())
			{
				stacki3.push(-1);
				stacki2.push(stacki1.top());
				stacki1.pop();
			}
		}
	}

	while (!stacki3.empty())
	{
		printf("%d ", stacki3.top());
		stacki3.pop();
	}

	return 0;
}