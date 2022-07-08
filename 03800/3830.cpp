//교수님은 기다리지 않는다
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


class P
{
public:
	P(int n) :mN(n) 
	{
		input();
	}

	void Query()
	{
		char Q;
		cin >> Q;

		if (Q == '!')
			update();
		else
			printAns();
	}


private:
	void input()
	{
		mUnion.resize(mN + 1, {-1, 0});
	}

	void printAns()
	{
		int a, b;
		cin >> a >> b;

		int aHead = findHead(a),
			bHead = findHead(b);

		if (aHead == bHead)
			cout << mUnion[b].second - mUnion[a].second << "\n";
		else
			cout << "UNKNOWN\n";
	}

	void update()
	{
		int a, b, w;
		cin >> a >> b >> w;

		merge(a, b, w);
	}

	int findHead(const int a)
	{
		if (mUnion[a].first < 0)
			return a;

		int head = findHead(mUnion[a].first);
		mUnion[a] = { head, mUnion[mUnion[a].first].second + mUnion[a].second };
		return mUnion[a].first;
	}

	void merge(int a, int b, int w)
	{
		int aHead = findHead(a),
			bHead = findHead(b);
		if (aHead == bHead)
			return;

		mUnion[bHead] = { aHead, w + mUnion[a].second- mUnion[b].second};
	}



private:
	vpii mUnion;
	int mN;

};

void Solve()
{
	int n, m;

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		P p(n);
		while (m--)
			p.Query();
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}