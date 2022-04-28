//여우가 정보섬에 올라온 이유
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
typedef std::pair<int, int> pi;
typedef std::vector<int> vi;

const int DIV = 1'000'000'007;

class Fenwick
{
public:
	Fenwick()
	{
		solve();
	}

private:
	void solve()
	{
		int n;
		std::cin >> n;

		std::vector<pi> poses(n);
		for (auto& [x, y] : poses)
		{
			std::cin >> x >> y;
		}

		std::sort(poses.begin(), poses.end(), [](pi& a, pi& b) -> bool
			{
				return a.first < b.first;
			});

		int order = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (poses[i].first != poses[i + 1].first)
				poses[i].first = order++;
			else
				poses[i].first = order;
		}
		poses.back().first = order;
		mN = order;
		mFenwick.resize(mN + 1);

		std::sort(poses.begin(), poses.end(), [](auto& a, auto& b) -> bool
			{
				return a.second > b.second;
			});

		int prevY = poses.front().second;
		int uppernum = 0, ans = 0;
		std::stack<int> yTemp;
		for (auto& [a, b] : poses)
		{
			if (prevY != b)
			{
				uppernum += int(yTemp.size());
				while (!yTemp.empty())
				{
					update(yTemp.top());
					yTemp.pop();
					prevY = b;
				}
			}

			yTemp.push(a);
			ans = (ans + ((long long)sum(a - 1) * (uppernum - sum(a)))) % DIV;
		}

		std::cout << ans;
	}

	inline void update(int idx)
	{
		for (int i = idx; i <= mN; i += (i & -i))
			mFenwick[i]++;
	}

	inline int sum(int i)
	{
		int ans = 0;
		for (; i > 0; i -= (i & -i))
			ans += mFenwick[i];

		return ans;
	}

private:
	vi mFenwick;
	int mN;

};

void Solve()
{
	Fenwick fen;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}