//문자열 제곱
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;

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

	std::string S;
	while (std::cin >> S)
	{
		if (S[0] == '.')
			break;

		vi pi = getpi(S);
		int temp = int(S.length() - pi[S.length() - 1]);

		if (S.length() % temp == 0)
			std::cout << S.length() / temp << "\n";
		else
			std::cout << 1 << "\n";

	}

	return 0;
}