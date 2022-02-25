//부분 문자열
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
typedef std::vector<int > vi;

bool KMP(const std::string& T, const std::string& P, const vi& pi)
{
	int begin = 0, match = 0, end = T.length() - P.length(), complete = P.length();
	vi answer;
	while (begin <= end)
	{
		if (T[begin + match] == P[match])
		{
			match++;
			if (match == complete)
			{
				return 1;
			}
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

	std::string T, P;
	std::getline(std::cin, T, '\n');
	std::getline(std::cin, P, '\n');

	vi pi = getpi(P);
	if (KMP(T, P, pi))
		std::cout << 1;
	else
		std::cout << 0;

	return 0;
}