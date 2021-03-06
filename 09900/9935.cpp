//문자열 폭발
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::string s, c4;
	std::cin >> s >> c4;
	std::stack<int> box;
	std::stack<char> ans;

	int now = 0, len = c4.length();
	std::reverse(c4.begin(), c4.end());

	std::string::reverse_iterator riter{s.rbegin()};
	for (;riter!=s.rend();++riter)
	{
		ans.push(*riter);
		if (*riter == c4[0])
		{
			if (len == 1)
				ans.pop();
			else
			{
				now = 1;
				box.push(now);
			}
		}
		else if (*riter == c4[now])
		{
			box.push(++now);
			if (now == len) //expl
			{
				while (now--)
				{
					box.pop();
					ans.pop();
				}
				if (!box.empty())
					now = box.top();
				else
					now = 0;
			}
		}
		else
		{
			while (!box.empty())
				box.pop();
			now = 0;
		}
	}
	if (ans.empty())
		std::cout << "FRULA";
	else
	{
		while (!ans.empty())
		{
			std::cout << ans.top();
			ans.pop();
		}
	}

	return 0;
}