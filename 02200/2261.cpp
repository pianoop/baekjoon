//가장 가까운 두 점
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

class pi
{
public:
	int x, y;

	pi(int a, int b) :x(a), y(b) {}
	pi():x(0),y(0) {}

	bool operator < (const pi& v)const
	{
		if (y == v.y)
			return x < v.x;
		else
			return y < v.y;
	}
};

bool cmp(const pi& a, const pi& b)
{
	return a.x < b.x;
}

int pow2(int a)
{
	return a * a;
}

int distancepow2(const pi& a, const pi& b)
{
	return pow2(b.y - a.y) + pow2(b.x - a.x);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<pi> vpi(N);
	for (auto& [a, b] : vpi)
		std::cin >> a >> b;

	std::sort(vpi.begin(), vpi.end(), cmp);

	std::set<pi> cand;
	int dpow2 = distancepow2(vpi[0], vpi[1]);
	cand.insert(vpi[0]);
	cand.insert(vpi[1]);

	if (!vpi.empty())
	{
		int start = 0;
		for (int i = 2;i < N;i++)
		{
			auto now = vpi[i];

			while (start < i)
			{
				auto temp = vpi[start];
				int x = now.x - temp.x;
				if (pow2(x) > dpow2)
				{
					cand.erase(temp);
					start++;
				}
				else
					break;
			}
			int d = int(sqrt(double(dpow2))) + 1;
			pi low = pi(-10001, now.y - d);
			pi up = pi(10001, now.y + d);
			auto lower = cand.lower_bound(low);
			auto upper = cand.upper_bound(up);
			for (auto it = lower;it != upper;it++)
			{
				int disit = distancepow2(now, *it);
				if (dpow2 > disit)
					dpow2 = disit;
			}
			cand.insert(now);
		}
	}

	std::cout << dpow2;

	return 0;
}