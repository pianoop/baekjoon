//원 영역
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
typedef long long ll;
typedef std::pair<int, int> pi;

bool cmp(const pi& a, const pi& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

class StackItem
{
public:
	int pos;
	int state;
	StackItem(int p, int s) :pos(p), state(s) {}
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<pi> pair_pr;
	pair_pr.reserve(2 * N);
	for (int p, r, i = 0;i < N;i++)
	{
		std::cin >> p >> r;
		pair_pr.push_back({ p - r, 0 });
		pair_pr.push_back({ p + r, 1 });
	}
	std::sort(pair_pr.begin(), pair_pr.end(), cmp);

	int ans = N+1, last = 0;
	std::stack<StackItem> st1;
	for (auto& [a, b] : pair_pr)
	{
		if (st1.empty())    //오직 ( 가 들어오는 구조
		{
			st1.push(StackItem(a, b));
			last = a;
		}
		else if (!b)  // ( 와 접촉
		{
			if (last != a)
				st1.top().state = -1;
			else if(st1.top().state!=-1&&last==a)
			{
				st1.top().state = 1;
			}
			st1.push(StackItem(a, b));
			last = a;
		}
		else  // ) 와 접촉
		{
			if (st1.top().state==1 && last==a)
			{
				ans++;
			}
			st1.pop();
			if (!st1.empty()&&st1.top().state!=-1)
				last = a;
		}
	}

	std::cout << ans;

	return 0;
}
