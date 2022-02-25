북서풍
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef std::pair<int, int> pi;
int size;

class SegTree
{
public:
	std::vector<int> tree;
	SegTree() 
	{
		tree.resize(size*2, 0);
	}

	void root(int n)
	{
		n += size / 2;
		while (n > 0)
		{
			tree[n]++;
			n /= 2;
		}
	}
	int search(int node, int treeL, int treeR, int left, const int& right)
	{
		if (treeL > right || treeR < left)
			return 0;
		if (left <= treeL && right >= treeR)
			return tree[node];

		int mid = (treeL + treeR) / 2;
		return search(node * 2, treeL, mid, left, right)
			+ search(node * 2 + 1, mid + 1, treeR, left, right);
	}
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	while (N--)
	{
		int M;
		std::cin >> M;
		size = 1 << ((int)ceil(log2(M)+0.000001) + 1);
		SegTree ST1;
		std::vector<pi> islandpos;
		islandpos.reserve(M);
		for (int x,y,i = 0;i < M;i++)
		{
			std::cin >> x >> y;
			islandpos.push_back({ x,y });
		}
		std::sort(islandpos.begin(), islandpos.end(), [](const pi& a, const pi& b)
			{
				return a.second < b.second;
			});
		
		std::vector<int> temp;
		temp.reserve(M);
		temp.push_back(0);
		for (int rank=0, i=1;i<M;i++)
		{
			if (islandpos[i].second != islandpos[i - 1].second)
				rank++;
			temp.push_back(rank);
		}
		for (int i = 0;i < M;i++)
		{
			islandpos[i].second = temp[i];
		}

		std::sort(islandpos.begin(), islandpos.end(), [](const pi & a, const pi & b)
		{
			if (a.first == b.first)
				return a.second > b.second;
			return a.first < b.first;
		});

		long long ans = 0;
		for (auto& [a, b]: islandpos)
		{
			ans += ST1.search(1, 0, size / 2 - 1, b, size / 2);
			ST1.root(b);
		}
		std::cout << ans<<"\n";
	}
	
	return 0;
}