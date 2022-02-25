//이진 검색 트리
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

void solve(int left, int right, const vi& pre, std::stack<int>& ans)
{
	if (left > right)
		return;

	ans.push(pre[left]);

	if (left == right)
		return;

	int rtop = std::upper_bound(pre.begin() + left, pre.begin()+right+1, pre[left])-pre.begin();

	solve(rtop, right, pre, ans);
	solve(left + 1, rtop - 1, pre, ans);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	vi preorder;
	preorder.reserve(10000);
	int x;
	while (std::cin >> x)
		preorder.push_back(x);
	
	std::stack<int> ans;
	solve(0, (int)preorder.size() - 1, preorder, ans);

	while (!ans.empty())
	{
		std::cout << ans.top() << "\n";
		ans.pop();
	}

	return 0;
}