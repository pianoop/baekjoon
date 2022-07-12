//일하는 세포
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


const int DIV = 1'000'000'007;

vvi operator*(const vvi& A, const vvi& B)
{
	size_t n = A.size();
	vvi C(n, vi(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				C[i][j] = (C[i][j] + ((ll)A[i][k] * B[k][j])) % DIV;

			C[i][j] %= DIV;
		}
	}

	return C;
}

class Q
{
public:
	Q()
	{
		input();
	}

	void Solve()
	{
		vvi ans = powMatrix(mTMap, mD / mT);
		ans = ans * mRemainder;

		for (auto& nm : ans)
		{
			for (auto& i : nm)
				cout << i << " ";
			cout << "\n";
		}
	}


private:
	void input()
	{
		cin >> mT >> mN >> mD;

		mTMap.resize(mN, vi(mN));
		for (int i = 0; i < mN; i++)
			mTMap[i][i] = 1;

		int R = mD % mT;
		for (int i = 0; i < mT; i++)
		{
			if (i == R)
				mRemainder = mTMap;

			init();
		}
	}

	void init()
	{
		int n, a, b, c;
		cin >> n;

		vvi tmp(mN, vi(mN));
		while (n--)
		{
			cin >> a >> b >> c;
			tmp[a - 1][b - 1] = c;
		}

		mTMap = mTMap * tmp;
	}

	vvi powMatrix(vvi A, int b)
	{
		vvi ret(mN, vi(mN, 0));
		for (int i = 0; i < mN; i++)
			ret[i][i] = 1;

		while (b)
		{
			if (b & 1)
				ret = (ret * A);

			A = (A * A);
			b >>= 1;
		}

		return ret;
	}

private:
	vvi mTMap, mRemainder;
	int mT, mN, mD;

};


void Solve()
{
	Q q;
	q.Solve();

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}