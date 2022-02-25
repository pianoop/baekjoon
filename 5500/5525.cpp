//IOIOI
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	std::string s1;

	int ans = 0;
	std::cin >> s1;
	for (int i = 0;i < M;i++)
	{
		if (s1[i] == 'I')
		{
			int oi = 0;
			for (++i;i < M - 1;i += 2)
			{
				if (s1[i] == 'O' && s1[i + 1] == 'I')
				{
					oi++;
					if (oi == N)
					{
						ans++;
						oi--;
					}
				}
				else
				{
					i--;
					break;
				}
			}
		}
	}

	std::cout << ans;

	return 0;
}