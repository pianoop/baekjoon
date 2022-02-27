//개미굴
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <map>
typedef std::vector<std::string> vs;

class Trie
{
public:
	Trie()
	{
		bmtail = false;
	}
	~Trie()
	{
		for (auto& a : mchild)
			delete a.second;
	}

	void Insert(const vs vs, const int n)
	{
		if (n == int(vs.size()))
		{
			bmtail = true;
			return;
		}

		mchild.insert({ vs[n],new Trie});
		mchild[vs[n]]->Insert(vs, n + 1);
	}
	void Print(const int n)
	{
		for (auto& T : mchild)
		{
			for (int i = 0;i < n;i++)
				printf("--");
			std::cout << T.first << "\n";
			T.second->Print(n + 1);
		}
	}

private:
	std::map<std::string, Trie*> mchild;
	bool bmtail;
};

void SetTrie(Trie& trie)
{
	int N;
	std::cin >> N;

	while (N--)
	{
		int k;
		std::cin >> k;
		std::string s;
		vs vtemp;
		vtemp.reserve(k);
		while (k--)
		{
			std::cin >> s;
			vtemp.push_back(s);
		}

		trie.Insert(vtemp, 0);
	}
}

int main()
{
	Trie trie;
	SetTrie(trie);
	trie.Print(0);

	return 0;
}