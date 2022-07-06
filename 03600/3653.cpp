//영화 수집
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;


class Q
{
public:
	Q()
	{
		mSize = 1 << 21;
		mFenwick.resize(mSize + 1);
		updateM(1);

		input();
	}

	void Solve()
	{
		int k = 1 << 20, tmp = k;
		vi trans(mN + 1);
		for (auto& i : trans)
			i = tmp++;

		int m;
		cin >> m;
		while (m--)
		{
			cin >> tmp;

			cout << sum(trans[tmp]) << " ";
			updateM(trans[tmp]);
			updateP(k);
			trans[tmp] = k--;
		}
		cout << "\n";
	}


private:
	void input()
	{
		cin >> mN;

		int k = mSize >> 1,  end = k + mN, tmp;
		for (int i = k + 1; i <= end; i++)
		{
			tmp = i + (i & -i);
			if (tmp <= mSize)
				mFenwick[tmp] += ++mFenwick[i];
		}
	}

	inline void updateP(int idx)
	{
		for (int i = idx; i <= mSize; i += (i & -i))
			mFenwick[i]++;
	}

	inline void updateM(int idx)
	{
		for (int i = idx; i <= mSize; i += (i & -i))
			mFenwick[i]--;
	}

	inline int sum(int i)
	{
		int ans = 0;
		for (; i > 0; i -= (i & -i))
			ans += mFenwick[i];

		return ans;
	}


private:
	vi mFenwick;
	int mN, mSize;

};


void Solve()
{
	int T;
	cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}