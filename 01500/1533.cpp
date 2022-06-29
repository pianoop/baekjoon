//길의 개수
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


const int DIV = 1'000'003;

vvi operator*(const vvi& A, const vvi& B)
{
	size_t n = A.size();
	vvi C(n , vi(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				C[i][j] += ((long long)A[i][k] * B[k][j]) % DIV;

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
		trans();
		cout << powMatrix(mEdges, mT);
	}


private:
	void input()
	{
		cin >> mN >> mS >> mD >> mT;
		mD--, mS--; //행렬의 idx와 맞춰주기

		mMap.resize(mN, vector<char>(mN));
		vector<char> max(mN,1);
		for (int i = 0; i < mN; i++)
		{
			for (int j = 0; j < mN; j++)
			{
				char& now = mMap[i][j];
				cin >> now;
				now -= 48;

				if (now > max[j])
					max[j] = now;
			}
		}

		mNextidx.resize(mN);
		mTot = mN - 1;
		for (int i = 0; i < mN; i++)
		{
			if (max[i] > 1)
			{
				mTot += max[i] - 1;
				mNextidx[i] = mTot;
			}
		}
		mTot++;

		mEdges.resize(mTot, vi(mTot));
		int i = mN - 1, ii = 0;
		for (auto idx : mNextidx)
		{
			if (idx != 0)
			{
				for (i++; i < idx; i++)
					mEdges[i][i + 1] = 1;
				mEdges[idx][ii] = 1;
			}
			ii++;
		}
	}

	void trans()
	{
		int F;
		for (int i = 0; i < mN; i++)
		{
			for (int j = 0; j < mN; j++)
			{
				int now = mMap[i][j];

				if (now == 1)
					mEdges[i][j] = 1;
				else if (now > 1)
					mEdges[i][mNextidx[j] - now + 2] = 1;
			}
		}
	}

	int powMatrix(vvi A, int b)
	{
		vvi ret(mTot, vi(mTot, 0));
		for (int i = 0; i < mTot; i++)
			ret[i][i] = 1;

		while (b)
		{
			if (b & 1)
			{
				ret = (ret * A);
			}
			A = (A * A);
			b >>= 1;
		}

		return ret[mS][mD];
	}


private:
	vvi mEdges;
	vector<vector<char> > mMap;
	vi mNextidx;
	int mN, mS, mD, mT, mTot;

};


void Solve()
{
	Q ans;
	ans.Solve();
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	Solve();

	return 0;
}