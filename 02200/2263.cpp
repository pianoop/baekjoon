//트리의 순회
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

void solve(int left, int right, int left2, int right2, const vi& po, const vi& io, const vi& ioidx)
{
	if (left > right)
		return;
	if (left == right)
	{
		std::cout << io[left] << " ";
		return;
	}
	int top = ioidx[po[right2]]-left;
	std::cout << io[top+left] << " ";

	solve(left, left + top - 1, left2 , left2+top-1, po, io, ioidx);
	solve(left + top + 1, right, left2+top ,right2-1, po, io, ioidx);

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N;
	std::cin >> N;

	vi inorder(N), postorder(N), inidx(N+1);
	{
		int i = 0;
		for (auto& a : inorder)
		{
			std::cin >> a;
			inidx[a] = i++;
		}
	}
	for (auto& a : postorder)
		std::cin >> a;
	

	solve(0, N - 1, 0, N-1, postorder, inorder, inidx);

	return 0;
}