//속타는 저녁 메뉴
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<char> vc;

int GCD(int a, int b)
{
	return a % b == 0 ? b : GCD(b, a % b);
}

template<typename T>
int KMP(const T& P, const T& S, const vi& Pi)
{
	int ans=0, begin = 0, match = 0, end = int(S.size()), fin =int(P.size());

	while (begin + match < end)
	{
		if (S[begin + match] == P[match])
		{
			match++;
			if (match == fin)
			{
				ans++;
				begin += match - Pi[match - 1];
				match = Pi[match - 1];
			}
		}
		else
		{
			if (match == 0)
				begin++;
			else
			{
				begin += match - Pi[match - 1];
				match = Pi[match - 1];
			}
		}
	}

	return ans;
}

template <typename T>
vi getpi(const T& P)
{
	vi pi(int(P.size()));
	int end = int(P.size());
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

	int n;
	std::cin >> n;

	vc P(n),S(n);
	for (auto& a : P)
		std::cin >> a;
	for (auto& a : S)
		std::cin >> a;

	vi pi = getpi(P);
	int tmp = KMP(P, S, pi);
	S.insert(S.end(), S.begin(), S.end());
	int ans = KMP(P, S, pi) - tmp;

	tmp = GCD(ans, n);
	std::cout << ans / tmp << "/" << n / tmp;

	return 0;
}