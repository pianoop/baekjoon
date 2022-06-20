//최솟값 찾기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;


class Pair
{
public:
	int idx, val;

	bool operator<(const Pair& other) const
	{
		return val > other.val;
	}
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
		std::priority_queue<Pair,std::vector<Pair> > pqMin;
		for (int i = 0; i < mN; i++, left++)
		{
			std::cin >> val;
			pqMin.push({ i, val });

			while (pqMin.top().idx <= left)
				pqMin.pop();

			std::cout << pqMin.top().val << " ";
		}
	}


private:
	void input()
	{
		std::cin >> mN >> mL;
	}

	int recur(int nm, int m, int bit)
	{
		
	}


private:
	vi mData;
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