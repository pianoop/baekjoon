//광고
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

vi getpi(const std::string& P)
{
	vi pi(P.length());
	int end = P.length();
	int begin = 1, match = 0;
	while (begin + match < end)
	{
		if (P[begin + match] == P[match])
		{
			match++;
			pi[begin + match - 1] = match;
		}
		else
		{
			if (match == 0)
				begin++;
			else
			{
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}

	return pi;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int L;
	std::string S;
	std::cin >> L >> S;

	vi pi = getpi(S);
	std::cout << L - pi[L - 1];
		
	return 0;
}