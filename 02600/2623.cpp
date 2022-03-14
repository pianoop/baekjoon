//음악프로그램
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Topology
{
public:
	Topology()
	{
		Input();
	}

	int Size()
	{
		return mN;
	}

	void OrderPrint()
	{
		std::queue<int> ans;
		Sort(ans);

		if (ans.size() != mN)
			printf("0");
		else
		{
			while (!ans.empty())
			{
				printf("%d\n", ans.front());
				ans.pop();
			}
		}
	}


private:
	void Input()
	{
		int M;
		std::cin >> mN >> M;;
		mEdges.resize(mN + 1);
		mPrevnums.resize(mN + 1);
		while (M--)
		{
			int tmpnum, prev, next;
			std::cin >> tmpnum >> prev;
			while (--tmpnum)
			{
				std::cin >> next;
				mEdges[prev].push_back(next);
				mPrevnums[next]++;
				prev = next;
			}
		}
	}

	void Sort(std::queue<int>& ans)
	{
		std::queue<int> box;
		for (int i=1;i<=mN;i++)
		{
			if (mPrevnums[i] == 0)
			{
				box.push(i);
				ans.push(i);
			}
		}

		while (!box.empty())
		{
			for (auto& next : mEdges[box.front()])
			{
				if (--mPrevnums[next] == 0)
				{
					box.push(next);
					ans.push(next);
				}
			}
			box.pop();
		}
	}

private:
	vvi mEdges;
	vi mPrevnums;
	int mN;
};

void Solve()
{
	Topology singer;
	singer.OrderPrint();

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}