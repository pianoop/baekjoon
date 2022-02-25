//히스토그램에서 가장 큰 직사각형
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
typedef std::vector<int> vi;

void init(vi& his, vi& tree, int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = start;
	}
	else
	{
		init(his, tree, node * 2, start, (start + end) / 2);
		init(his, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = (his[tree[node * 2]] < his[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1]);
	}
}

int range_min(vi& his, vi& tree, int node, const int &start, const int &end, int left, int right)
{
	if (left > end || right < start) //교집합 없으면 제거
	{
		return -1;
	}
	if (left >= start && right <= end) //L,R 구간보다 찾는 범위가 클 경우(교집합 있으면서)
	{
		return tree[node];
	}
	int min1 = range_min(his, tree, node * 2, start, end, left, (left + right) / 2);
	int min2 = range_min(his, tree, node * 2 + 1, start, end, (left + right) / 2 + 1, right);

	if (min1 == -1)
		return min2;
	else if (min2 == -1)
		return min1;

	return (his[min1] < his[min2] ? min1 : min2);
}

ll largest(vi& his, vi& tree, int start, int end, const int& n)
{
	int min = range_min(his, tree, 1, start, end, 0, n - 1); // = 구간의 최소값의 배열 넘버
	ll area = (ll)his[min] * (ll)(end - start + 1);
	if (start < min) //최솟값 기준 왼쪽
	{
		ll temp = largest(his, tree, start, min - 1,n);
		if (area < temp)
			area = temp;
	}
	if (min < end) //우측
	{
		ll temp = largest(his, tree, min + 1, end,n);
		if (area < temp)
			area = temp;
	}
	return area;
}

int main()
{
	int n;

	while (scanf("%d", &n) && n != 0)
	{
		vi his(n);
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &his[i]);
		}
		int hisize = his.size();
		int h = (int)(ceil(log2(n)) + 1e-9);
		int treesize = (1 << (h + 1));
		vi tree(treesize);
		init(his, tree, 1, 0, n - 1);
		printf("%lld\n", largest(his, tree, 0, n - 1,hisize));
	}

	return 0;
}