//전화번호 목록
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<char> vc;

class Trie
{
public:
	Trie()
	{
		bmtail = false;
		for (int i = 0;i < 10;i++)
			mnum[i] = nullptr;
	}
	~Trie()
	{
		for (int i = 0;i < 10;i++)
			delete mnum[i];
	}

	void insert(const char* s)
	{
		if (*s == 0)
		{
			bmtail = true;
			return;
		}

		int now = *s - '0';
		if (mnum[now] == nullptr)
			mnum[now] = new Trie;
		mnum[now]->insert(s + 1);
	}
	bool find(const char* s)
	{
		if (*s == 0 || bmtail)
		{
			return true;
		}

		int now = *s - '0';
		if (mnum[now] == nullptr)
			return false;

		return mnum[now]->find(s + 1);
	}

private:
	Trie* mnum[10];
	bool bmtail;
};

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);

		bool bflag = true;
		char phonenum[11];
		Trie trie;
		while (n--)
		{
			scanf("%s", phonenum);
			if (trie.find(phonenum))
			{
				bflag = false;
				while(n--)
					scanf("%s", phonenum);
				printf("NO\n");
				break;
			}
			trie.insert(phonenum);
		}
		if (bflag)
			printf("YES\n");
	}

	return 0;
}