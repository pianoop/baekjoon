//나는 친구가 적다 (Large)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
typedef std::vector<int > vi;

bool kmp(const std::string& S, const std::string P, const vi& pi)
{
	int end = int(S.length());
	int begin = 0, match = 0, m = int(pi.size()), num=0;

	while (begin + match + num < end)
	{
		if (S[begin + match + num] < 58)
		{
			num++;
		}
		else if (S[begin + match + num] == P[match])
		{
			match++;
			if (match == m)
				return 1;
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

	return 0;
}

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

	std::string S, P;
	std::cin >> S >> P;

	
	vi pi = getpi(P);

	std::cout << kmp(S,P,pi);

	return 0;
}