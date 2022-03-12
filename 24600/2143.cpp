//두 배열의 합
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <unordered_map>
typedef std::vector<int> vi;

void InputA(std::unordered_map<int, int>& Amap)
{
	int n;
	std::cin >> n;
	vi A(n);
	for (auto& a : A)
	{
		std::cin >> a;
		auto temp = Amap.insert({ a,1 });
		if (!temp.second)
			temp.first->second++;
	}

	vi temp1 = A, temp2(n);
	vi* tmp1 = &temp1;
	vi* tmp2 = &temp2;
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			(*tmp2)[j] = (*tmp1)[j-1]+A[j];

			auto temp = Amap.insert({ (*tmp2)[j],1 });
			if (!temp.second)
				temp.first->second++;
		}
		std::swap(tmp1, tmp2);
	}
}

long long Sumsubset_AB(std::unordered_map<int, int>& Amap, const int& T)
{
	int m;
	long long ans = 0;
	std::cin >> m;
	vi B(m);
	for (auto& b : B)
	{
		std::cin >> b;
		auto temp = Amap.find(T - b);
		if (temp != Amap.end())
			ans += temp->second;
	}

	vi temp1 = B, temp2(m);
	vi* tmp1 = &temp1;
	vi* tmp2 = &temp2;
	for (int i = 1; i < m; i++)
	{
		for (int j = i; j < m; j++)
		{
			(*tmp2)[j] = (*tmp1)[j - 1] + B[j];

			auto temp = Amap.find(T - (*tmp2)[j]);
			if (temp != Amap.end())
				ans += temp->second;
		}
		std::swap(tmp1, tmp2);
	}

	return ans;
}

void Solve()
{
	int T;
	std::cin >> T;
	std::unordered_map<int, int> Asubtotal;
	InputA(Asubtotal);
	printf("%lld",Sumsubset_AB(Asubtotal, T));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
} 