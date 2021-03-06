//DSLR
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

class DSLR
{
public:
	int total;

	DSLR(int t) :total(t) {}
	~DSLR() {}

	int D()
	{
		int t = (total * 2) % 10000;
		return t;
	}
	int S()
	{
		int t;
		if (total == 0)
			t = 9999;
		else
			t = total - 1;
		return t;
	}
	int L()
	{
		int t = (total % 1000) * 10 + total / 1000;
		return t;
	}
	int R()
	{
		int t = total / 10 + (total % 10)*1000;
		return t;
	}
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
	{
		int A, B;
		std::cin >> A >> B;

		std::vector<std::pair<int, char>> oneto9999(10000, {-1,NULL});
		std::queue<int> box;
		box.push(A);
		oneto9999[A] = { -2,'X' };

		while (!box.empty())
		{
			DSLR temp(box.front());
			if (temp.total == B)
				break;

			int A = temp.D();
			if (oneto9999[A].first==-1)
			{
				box.push(A);
				oneto9999[A] = {temp.total,'D'};
			}

			A = temp.S();
			if (oneto9999[A].first == -1)
			{
				box.push(A);
				oneto9999[A] = { temp.total,'S' };
			}

			A = temp.L();
			if (oneto9999[A].first == -1)
			{
				box.push(A);
				oneto9999[A] = { temp.total,'L' };
			}

			A = temp.R();
			if (oneto9999[A].first == -1)
			{
				box.push(A);
				oneto9999[A] = { temp.total,'R' };
			}

			box.pop();
		}
		
		std::stack<char> ans;
		while (B != A)
		{
			ans.push(oneto9999[B].second);
			B = oneto9999[B].first;
		}

		while (!ans.empty())
		{
			std::cout << ans.top();
			ans.pop();
		}
		std::cout << "\n";
	}

	return 0;
}