//찾기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

vi KMP(const std::string& T, const std::string& P, const vi& pi)
{
	int n = 0, begin = 0, match = 0, end = T.length() - P.length(), complete = P.length();
	vi answer;
	while (begin <= end)
	{
		if (T[begin + match] == P[match])
		{
			match++;
			if (match == complete)
			{
				answer.push_back(begin + 1);
				begin += match - pi[match - 1];
				match = pi[match - 1];
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

	return answer;
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
	vi answer = KMP(T, P, pi);

	std::cout << answer.size() << "\n";
	for (auto& a : answer)
		std::cout << a << " ";

	return 0;
}