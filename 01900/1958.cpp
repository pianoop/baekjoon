//LCS 3
//-------------------------------------------------------------------
#include <iostream>
#include <vector>

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	std::string s1, s2, s3;
	std::cin >> s1 >> s2 >> s3;
	int z = s3.length(), n = s2.length(), m = s1.length();

	std::vector<std::vector<std::vector<int> > >
		vvi(m + 1, std::vector<std::vector<int> >(n + 1, std::vector<int>(z + 1, 0)));

	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < z;k++)
			{
				if (s3[k] == s2[j] && s2[j] == s1[i])
				{
					vvi[i + 1][j + 1][k + 1] = vvi[i][j][k] + 1;
				}
				else
					vvi[i + 1][j + 1][k + 1] = Max(vvi[i][j + 1][k + 1]
						, Max(vvi[i + 1][j][k + 1], vvi[i + 1][j + 1][k]));
			}
		}
	}
	printf("%d", vvi[m][n][z]);
    
    return 0;
}