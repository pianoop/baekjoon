//세금
//-------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;


const int INTMAX = 400'000'000;

class Tri
{
public:
	int dest, cost, routeNum;

	bool operator<(const Tri& Other) const
	{
		return cost > Other.cost;
	}

};
typedef vector<Tri> vt;
typedef vector<vt> vvt;


class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		dijkstra();

		auto& DstDest = mDist[mD];
		for (auto tax : mTax)
		{
			int MIN = INTMAX;
			for (int i = 1; i < mN; i++)
				MIN = min(MIN, DstDest[i] + i * tax);

			cout << MIN << "\n";
		}
	}


private:
	void input()
	{
		int e;
		cin >> mN >> e >> mK >> mS >> mD;
		mN++;
		mEdges.resize(mN);
		mDist.resize(mN, vi(mN, INTMAX));

		auto& source = mDist[mS];
		for (int i = 0; i < mN; i++)
			source[i] = 0;

		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mEdges[b].push_back({ a, cost });
		}


		int tmp;
		mTax.push_back(0);
		for (int i = 0; i < mK; i++)
		{
			cin >> tmp;
			mTax.push_back(mTax.back() + tmp);
		}
	}

	void dijkstra()
	{
		priority_queue<Tri> box;
		box.push({ mS, 0, 0 });

		while (!box.empty())
		{
			auto [now, cost, rNum] = box.top();
			box.pop();

			auto& nowDist = mDist[now];
			if (nowDist[rNum] < cost)
				continue;

			int rNum1 = rNum + 1;
			for (auto [next, nextCost] : mEdges[now])
			{
				auto& nextDist = mDist[next];
				int NC = nowDist[rNum] + nextCost;
				if (nextDist[rNum1] > NC)
				{
					nextDist[rNum1] = NC;
					box.push({ next, nowDist[rNum] + nextCost, rNum1 });

					for (int i0 = rNum1 + 1; i0 < mN; i0++)
					{
						if (nextDist[i0] > NC)
							nextDist[i0] = NC;
						else
							break;
					}
				}
			}
		}
	}


private:
	vvpii mEdges;
	vvi mDist;
	vi mTax;
	int mN, mK, mS, mD;

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