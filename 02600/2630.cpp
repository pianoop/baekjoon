//색종이 만들기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

int b = 0, w = 0;
std::vector<std::vector<bool> > vv1;

void cut(int n, int m, int size)
{
	bool flag = vv1[n][m];
	if (size == 1)
	{
		if (flag)
			b++;
		else
			w++;
		return;
	}

	for (int i = n;i < n + size;i++)
	{
		for (int j = m;j < m + size;j++)
		{
			if (flag != vv1[i][j])
			{
				cut(n, m, size / 2);
				cut(n + size / 2, m, size / 2);
				cut(n, m + size / 2, size / 2);
				cut(n + size / 2, m + size / 2, size / 2);
				return;
			}
		}
	}
	if (flag)
		b++;
	else
		w++;
}

int main()
{
	int n;
	scanf("%d", &n);

	vv1.resize(n);
	bool bool1;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			std::cin >> bool1;
			vv1[i].push_back(bool1);
		}
	}
	cut(0, 0, n);
	std::cout << w << "\n" << b;

	return 0;
}