//후위 표기식
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::string s;
	std::cin >> s;

	std::stack<std::pair<char, int> > Box;
	for (int i = 0;i < (int)s.size();i++)
	{
		if (s[i] > 60)
			std::cout << s[i];
		else if (s[i] == '(')
		{
			Box.push({ s[i],3 });
		}
		else if (s[i] == ')')
		{
			while (Box.top().first != '(')
			{
				std::cout << Box.top().first;
				Box.pop();
			}
			Box.pop();
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			if (Box.empty() || Box.top().first == '(')
				Box.push({ s[i],2 });
			else
			{
				while (!Box.empty() && Box.top().second == 2)
				{
					std::cout << Box.top().first;
					Box.pop();
				}
				Box.push({ s[i],2 });
			}
		}
		else  //+-
		{
			if (Box.empty() || Box.top().first == '(')
				Box.push({ s[i],1 });
			else
			{
				while (!Box.empty() && Box.top().second!=3)
				{
					std::cout << Box.top().first;
					Box.pop();
				}
				Box.push({ s[i],1 });
			}
		}
	}

	while (!Box.empty())
	{
		std::cout << Box.top().first;
		Box.pop();
	}

	return 0;
}