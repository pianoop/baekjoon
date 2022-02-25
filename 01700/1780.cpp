//종이의 개수
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

int a = 0, b = 0, c = 0;
std::vector<std::vector<int> > vv1;

void Tree(int n, int m, int size)
{
	int flag = vv1[n][m];
	if (size == 1)
	{
		if (flag == -1)
			a++;
		else if (flag == 0)
			b++;
		else
			c++;
		return;
	}

	for (int i = n;i < n + size;i++)
	{
		for (int j = m;j < m + size;j++)
		{
			if (flag != vv1[i][j])
			{
				int divsize3 = size / 3;
				for (int ii = 0;ii < 3;ii++)
				{
					for (int jj = 0;jj < 3;jj++)
					{
						Tree(n + ii * divsize3, m + jj * divsize3, divsize3);
					}
				}
				return;
			}
		}
	}
	if (flag == -1)
		a++;
	else if (flag == 0)
		b++;
	else
		c++;
}

int main()
{
	int n;
	scanf("%d", &n);

	vv1.resize(n);
	int bool1;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			scanf("%d", &bool1);
			vv1[i].push_back(bool1);
		}
	}
	Tree(0, 0, n);
	printf("%d\n%d\n%d", a, b, c);

	return 0;
}