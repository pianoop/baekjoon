//알고리즘 수업 - 너비 우선 탐색 2
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		int cnt = 1;

		std::queue<int> box;
		box.push(mS);
		mCheck[mS] = 1;

		int now;
		while (!box.empty())
		{
			now = box.front();
			box.pop();

			for (auto& next : mEdges[now])
			{
				if (mCheck[next] == 0)
				{
					mCheck[next] = ++cnt;
					box.push(next);
				}
			}
		}


		for (int i = 1; i < mN; i++)
			std::cout << mCheck[i] << "\n";
	}

private:
	void input()
	{
		int e;
		std::cin >> mN >> e >> mS;

		mN++;
		mEdges.resize(mN);
		mCheck.resize(mN);

		int a, b;
		while (e--)
		{
			std::cin >> a >> b;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
		}

		for (auto& edges : mEdges)
			std::sort(edges.begin(), edges.end(), [](int& a, int& b)->bool
				{
					return a > b;
				});
	}


private:
	vvi mEdges;
	vi mCheck;
	int mN, mS;

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