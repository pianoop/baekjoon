//시계 사진들
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

bool KMP(const vi& P, const vi& S, const vi& Pi)
{
	int begin = 0, match = 0, end = int(S.size()), fin =int(P.size());

	while (begin + match < end)
	{
		if (S[begin + match] == P[match])
		{
			match++;
			if (match == fin)
				return 1;
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

	return 0;
}

vi getpi(const vi& P)
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

	vi vtmp(n);
	for (auto& a : vtmp)
		std::cin >> a;

	std::sort(vtmp.begin(), vtmp.end());
	vi clock1;
	clock1.reserve(n);
	clock1.push_back(vtmp[0] + 360000 - vtmp[n - 1]);
	for (int i = 1;i < n;i++)
		clock1.push_back(vtmp[i] - vtmp[i - 1]);

	for (auto& a : vtmp)
		std::cin >> a;

	std::sort(vtmp.begin(), vtmp.end());
	vi clock2;
	clock2.reserve(n);
	clock2.push_back(vtmp[0] + 360000 - vtmp[n - 1]);
	for (int i = 1;i < n;i++)
		clock2.push_back(vtmp[i] - vtmp[i - 1]);

	vtmp.clear(), vi().swap(vtmp);

	vtmp = getpi(clock1);
	clock2.insert(clock2.end(), clock2.begin(), clock2.end());
	if (KMP(clock1, clock2, vtmp))
		std::cout << "possible";
	else
		std::cout << "impossible";

	return 0;
}