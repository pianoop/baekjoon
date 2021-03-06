//트리 순회
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<char, char> pc;
typedef std::pair<int, int> pi;


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	const int Max = 100000;
	int N;
	std::cin >> N;

	pc* tree = new pc[N];
	char a, b, c;
	for (int i = 0;i < N;i++)
	{
		std::cin >> a >> b >> c;
		tree[(a-65)] = { b,c };
	}

	int order = 0, x;
	std::priority_queue<pi> Box1;
	Box1.push({ order++ , 0 });
	while (!Box1.empty())
	{
		x = Box1.top().second;
		Box1.pop();
		std::cout << char(x + 65);

		if (tree[x].first > 46)
		{
			Box1.push({ Max, tree[x].first - 65 });
		}
		if (tree[x].second > 46)
		{
			Box1.push({ order++, tree[x].second - 65 });
		}
	}
	std::cout << "\n";

	vi check(N);
	std::stack<int> Box2;
	Box2.push(0);
	while (!Box2.empty())
	{
		x = Box2.top();
		
		if (check[x] == 0)
		{
			check[x] = 1;
			if (tree[x].first > 46)
			{
				Box2.push(tree[x].first-65);
			}
		}
		else
		{
			std::cout << char(x+65);
			Box2.pop();
			if (tree[x].second > 46)
			{
				Box2.push(tree[x].second-65);
			}
		}
	}
	std::cout << "\n";

	vi(N).swap(check);
	Box2.push(0);
	while (!Box2.empty())
	{
		x = Box2.top();

		if (check[x] == 0)
		{
			check[x]++;
			if (tree[x].first > 46)
			{
				Box2.push(tree[x].first - 65);
			}
		}
		else if(check[x]==1)
		{
			check[x]++;
			if (tree[x].second > 46)
			{
				Box2.push(tree[x].second - 65);
			}
		}
		else
		{
			std::cout << char(x + 65);
			Box2.pop();
		}
	}

	delete[] tree;
	return 0;
}