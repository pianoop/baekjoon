//#include <iostream>
//#include <vector>

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	int N;
	scanf("%d", &N);
	std::string s1, s2;
	std::cin >> s1 >> s2;

	std::vector<std::vector<int> > vvi(s2.length() + 1, std::vector<int>(s1.length() + 1, 0));

	int n = s2.length(), m = s1.length();
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (s2[i] == s1[j])
				vvi[i + 1][j + 1] = vvi[i][j] + 1;
			else
				vvi[i + 1][j + 1] = Max(vvi[i][j + 1], vvi[i + 1][j]);
		}
	}
	int max = 0;
	for(int j=1;j<=m;j++)
	{ 
		if (max < vvi[n][j])
			max = vvi[n][j];
	}
	printf("%d", max);

	return 0;
}