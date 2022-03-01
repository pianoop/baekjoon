//휴대폰 자판
//-------------------------------------------------------------------
#include <iostream>

class Trie
{
public:
	Trie()
	{
		bmtail = false;
		for (int i = 0;i < 26;i++)
			mnum[i] = nullptr;
	}
	/*~Trie()
	{
		delete[] mnum;
	}*/

	void Insert(const char* s)
	{
		if (*s == 0)
		{
			bmtail = true;
			return;
		}

		int now = *s - 'a';
		if (mnum[now] == nullptr)
			mnum[now] = new Trie;
		mnum[now]->Insert(s + 1);
	}

	void SumButton(int& ans)
	{
		for (auto& m : mnum)
		{
			if (m != nullptr)
			{
				m->SumButton_sub(ans, 1);
				delete m;
			}
		}
	}

	void SumButton_sub(int& ans, int n)
	{
		if (bmtail)
			ans += n;

		int temp = 0, start;
		for (int i=0;i<26;i++)
		{
			if (mnum[i] != nullptr)
			{
				temp++;
				if (temp > 1)
					break;
				start = i;
			}
		}

		if (temp == 0)
			return;
		else
		{

			if (temp == 1 && !bmtail)
			{
				mnum[start]->SumButton_sub(ans, n);
				delete mnum[start];
			}
			else if (temp == 1)
			{
				mnum[start]->SumButton_sub(ans, n + 1);
				delete mnum[start];
			}
			else
			{
				for (int i = start;i < 26;i++)
				{
					if (mnum[i] != nullptr)
					{
						mnum[i]->SumButton_sub(ans, n + 1);
						delete mnum[i];
					}
				}
			}
		}
	}

private:
	Trie* mnum[26];
	bool bmtail;
};

void Insert(Trie* trie, int N)
{
	std::string str;
	while (N--)
	{
		std::cin >> str;
		trie->Insert(&str[0]);
	}
}

void solve(int N)
{
	Trie* trie = new Trie;
	Insert(trie, N);

	int ans = 0;
	trie->SumButton(ans);
	printf("%.2f\n", ans / double(N));
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int N;
	while (std::cin >> N)
		solve(N);

	return 0;
}