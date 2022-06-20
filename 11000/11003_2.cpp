//최소값 찾기 (deque 사용)
//-------------------------------------------------------------------
#include <iostream>
#include <deque>


class Pair
{
public:
	int idx, val;

};

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int val, left = -mL;
		std::deque<Pair> dq;
		for (int i = 0; i < mN; i++, left++)
		{
			std::cin >> val;
			while (!dq.empty() && dq.back().val > val)
				dq.pop_back();
			
			dq.push_back({ i, val });
			while (dq.front().idx <= left)
				dq.pop_front();

			std::cout << dq.front().val << " ";
		}
	}


private:
	void input()
	{
		std::cin >> mN >> mL;
	}


private:
	int mN, mL;

};

void Solve()
{
	Q q;
	q.Solve();
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}