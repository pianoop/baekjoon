//2022는 무엇이 특별할까?
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vi1, vi2, vcheck;
int d, endflag = 0;

void bt(int fi = 0)
{
	if (fi == d)
	{
		endflag = 1;
		return;
	}
	for (int i = vi1[fi];i < d;i++)
	{
		if (fi == 0 && i == 0)
			i++;
		if (vcheck[i])
		{
			vi2[fi]=i;
			vcheck[i] = 0;
			if (i>vi1[fi])
			{
				for (int j = 0;j<d;j++)
				{
					if (vcheck[j])
					{
						vi2[fi + 1] = j;
						fi++;
						vcheck[j] = 0;
					}
				}
				endflag = 1;
				return;
			}
			bt(fi + 1);
			if (endflag)
				return;
			vcheck[i] = 1;
		}
	}
}

int main()
{
	int N, Max = 0;
	scanf("%d%d", &N, &d);

	for (int dd=1, i = 0;i < d; i++)
	{
		Max += dd*i;
		dd *= d;
	}
	if (N >= Max)
	{
		printf("-1");
		return 0;
	}

	vi2.resize(d, -1);
	vcheck.resize(d, 1);
	N++;
	for (int i = 0;i < d;i++)
	{
		vi1.push_back(N % d);
		N /= d;
	}
	std::reverse(vi1.begin(), vi1.end());
	bt();
	int ret = 0;
	for (int dd=1,i = 0;i < d;i++)
	{
		ret += dd * vi2[d - i - 1];
		dd *= d;
	}
	printf("%d", ret);

	return 0;
}