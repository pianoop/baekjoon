//전설
//-------------------------------------------------------------------
#include <iostream>
#include <map>
#include <bitset>
using namespace std;


bitset<2048> g_color;
bitset<2048> g_name;

class Trie
{
public:
	Trie()
	{
		bmTail = false;
	}

	~Trie()
	{
		for (auto& a : mChild)
			delete a.second;
	}


public:
	map<char, Trie*> mChild;
	bool bmTail;

};

class TrieHeader
{
public:
	TrieHeader()
	{
		mTrie = new Trie;
	}

	~TrieHeader()
	{
		delete mTrie;
	}

	void Input(int n, bool reverseFlag)
	{
		string str;
		if (!reverseFlag)
		{
			while (n--)
			{
				cin >> str;
				insert(str);
			}
		}
		else
		{
			while (n--)
			{
				cin >> str;
				insert2(str);
			}
		}
	}

	void Find(const string& str)
	{
		int cnt = 0;

		Trie* curr = this->mTrie;
		int end = (int)str.size();
		while (cnt < end)
		{
			if (curr->mChild.find(str[cnt]) != curr->mChild.end())
			{
				curr = curr->mChild[str[cnt]];
				if (curr->bmTail)
					g_color.set(cnt, true);

				cnt++;
			}
			else
				return;
		}
	}

	void Find2(const string& str)
	{
		Trie* curr = this->mTrie;
		int idx = (int)str.size() - 1;
		while (!(idx < 0))
		{
			if (curr->mChild.find(str[idx]) != curr->mChild.end())
			{
				curr = curr->mChild[str[idx]];
				if (curr->bmTail)
					g_name.set(idx, true);

				idx--;
			}
			else
				return;
		}
	}

private:
	void insert(const string& str)
	{
		Trie* curr = this->mTrie;
		int end = (int)str.size(), idx = 0;
		while (idx != end)
		{
			curr = curr->mChild.insert({ str[idx], new Trie }).first->second;
			idx++;
		}

		curr->bmTail = true;
	}

	void insert2(const string& str)
	{
		Trie* curr = this->mTrie;
		int idx = (int)str.size() - 1;
		while (idx >= 0)
		{
			curr = curr->mChild.insert({ str[idx], new Trie }).first->second;
			idx--;
		}

		curr->bmTail = true;
	}


private:
	Trie* mTrie;
};


void Solve()
{
	int C, N;
	cin >> C >> N;

	TrieHeader color, name;
	color.Input(C, false);
	name.Input(N,true);

	int Q;
	cin >> Q;

	string str;
	while (Q--)
	{
		g_color.reset(), g_name.reset();
		
		cin >> str;
		color.Find(str);
		name.Find2(str);

		bool flag = false;
		size_t end = str.size();
		for (size_t i = 0; i < end;)
		{
			if (g_color.test(i++) && g_name.test(i))
			{
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}