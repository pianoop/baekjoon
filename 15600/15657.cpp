//N과 M (8)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

void solve(int n, int i, const int& N, const int& M, const vi& sequence, std::stack<int> box)
{
	if (n == M)
	{
		std::stack<int> tmp;
		while (!box.empty())
		{
			tmp.push(box.top());
			box.pop();
		}
		while (!tmp.empty())
		{
			std::cout << tmp.top() << " ";
			tmp.pop();
		}
		std::cout << "\n";
		return;
	}

	for(;i<N;i++)
		{
			box.push(sequence[i]);
			solve(n + 1, i, N, M, sequence, box);
			box.pop();
		}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	vi sequence(N);
	for (auto& a : sequence)
		std::cin >> a;
	std::sort(sequence.begin(), sequence.end());
	solve(0, 0, N, M, sequence, std::stack<int>());

	return 0;
}