//오아시스 재결합
//-------------------------------------------------------------------
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> pii;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		stack<pii> stack;
		int n, now;
		long long cnt = 0;
		cin >> n >> now;

		stack.push({ now,1 });
		while (--n)
		{
			cin >> now;

			if (stack.top().first > now)
			{
				cnt++;
				stack.push({ now,1 });
			}
			else if(stack.top().first < now)
			{
				do
				{
					cnt += stack.top().second;
					stack.pop();
					if (stack.empty())
						break;
				}
				while (stack.top().first < now);

				if (stack.empty())
					stack.push({ now,1 });
				else if (stack.top().first > now)
				{
					cnt++;
					stack.push({ now,1 });
				}
				else
				{
					if (stack.size() > 1)
						cnt++;

					cnt += stack.top().second++;
				}
			}
			else
			{
				if (stack.size() > 1)
					cnt++;

				cnt += stack.top().second++;
			}
		}

		cout << cnt;
	}


private:
	void input()
	{

	}


private:


};


void Solve()
{
	Q q;
	q.Solve();
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}