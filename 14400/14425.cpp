//문자열 집합
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
	~Trie()
	{
		for (int i = 0;i < 26;i++)
			delete mnum[i];
	}

	void insert(const char* s)
	{
		if (*s == 0)
		{
			bmtail = true;
			return;
		}

		int now = *s - 'a';
		if (mnum[now] == nullptr)
			mnum[now] = new Trie;
		mnum[now]->insert(s + 1);
	}
	bool find(const char* s)
	{
		if (*s == 0)
		{
			if (bmtail)
				return true;
			else
				return false;
		}

		int now = *s - 'a';
		if (mnum[now] == nullptr)
			return false;

		return mnum[now]->find(s + 1);
	}

private:
	Trie* mnum[26];
	bool bmtail;
};

void Insert(Trie& trie, int N)
{
	std::string s;
	while (N--)
	{
		std::cin >> s;
		trie.insert(&s[0]);
	}
}

int Find(Trie& trie, int M)
{
	int sum = 0;
	std::string s;
	while (M--)
	{
		std::cin >> s;
		if (trie.find(&s[0]))
			sum++;
	}

	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	
	Trie trie;
	Insert(trie, N);
	printf("%d",Find(trie, M));

	return 0;
}