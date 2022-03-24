//낚시왕
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

typedef std::pair<int, int> pi;
typedef std::stack<pi> spi;

class Tri
{
public:
	Tri(int S = 0, int Z = 0, int o = 0, bool D = false) :s(S), z(Z), order(o), d(D) {}

	bool operator <(const Tri& other) const
	{
		return z < other.z;
	}

	int s, z, order;
	bool d;
}; typedef std::vector<Tri> vT;
typedef std::vector<vT> vvT;

// n, m 뒤집어짐
class FishingKing
{
public:
	FishingKing()
	{
		input();
	}

	~FishingKing()
	{
		delete mSharkPoses;
		delete mMap;
	}

	int Fishing()
	{
		int Sum = 0;

		if (mSharkPoses->empty())
			return Sum;

		for (int j = 0; j <= mM; j++)
		{
			if ((*mMap)[0][j].z != 0)
			{
				Sum += (*mMap)[0][j].z;
				(*mMap)[0][j] = { 0,0,0 };
				break;
			}
		}

		for (int i = 1; i <= mN; i++)
		{
			if (mSharkPoses->empty())
				return Sum;

			move(i);

			for (int j = 0; j <= mM; j++)
			{
				if ((*mMap)[i][j].z != 0)
				{
					Sum += (*mMap)[i][j].z;
					(*mMap)[i][j] = { 0,0,0 };
					break;
				}
			}
		}

		return Sum;
	}

private:
	void input()
	{
		int sharkN;
		std::cin >> mM >> mN >> sharkN;
		mMap = new vvT(mN, vT(mM));
		mN--, mM--;

		int tmpN2 = mN * 2, tmpM2 = mM * 2;
		int n, m, s, d, z;
		mSharkPoses = new spi;
		while (sharkN--)
		{
			std::cin >> m >> n >> s >> d >> z;
			n--, m--;
			mSharkPoses->push({ n , m });

			if (d == 1)
				(*mMap)[n][m] = { -(s % tmpM2),z,0,true };
			else if (d == 2)
				(*mMap)[n][m] = { s % tmpM2,z,0,true };
			else if (d == 3)
				(*mMap)[n][m] = { s % tmpN2,z,0,false };
			else
				(*mMap)[n][m] = { -(s % tmpN2),z, 0,false };
		}
	}

	void move(int order)
	{
		vvT* nowMap = new vvT(mN + 1, vT(mM + 1));
		spi* nowPoses = new spi;
		while (!mSharkPoses->empty())
		{
			auto nm = mSharkPoses->top();
			mSharkPoses->pop();

			auto tri = (*mMap)[nm.first][nm.second];
			if (tri.z == 0 || tri.order == order)
				continue;
			(*mMap)[nm.first][nm.second].order = order;

			if (tri.d)
			{
				nm.second = nm.second + tri.s;
				while (true)
				{
					if (nm.second < 0)
					{
						nm.second = -nm.second;
						tri.s = -tri.s;
						continue;
					}
					if (nm.second > mM)
					{
						nm.second = mM * 2 - nm.second;
						tri.s = -tri.s;
						continue;
					}
					break;
				}

				if ((*nowMap)[nm.first][nm.second] < tri)
				{
					(*nowMap)[nm.first][nm.second] = { tri.s,tri.z,order,true };
					nowPoses->push({ nm.first,nm.second });
				}
			}
			else
			{
				nm.first = nm.first + tri.s;
				while (true)
				{
					if (nm.first < 0)
					{
						nm.first = -nm.first;
						tri.s = -tri.s;
						continue;
					}
					if (nm.first > mN)
					{
						nm.first = mN * 2 - nm.first;
						tri.s = -tri.s;
						continue;
					}
					break;
				}

				if ((*nowMap)[nm.first][nm.second] < tri)
				{
					(*nowMap)[nm.first][nm.second] = { tri.s,tri.z,order,false };
					nowPoses->push({ nm.first,nm.second });
				}
			}
		}



		std::swap(mMap, nowMap);
		delete nowMap;
		std::swap(nowPoses, mSharkPoses);
		delete nowPoses;
	}

private:
	vvT* mMap;
	spi* mSharkPoses;
	int mN, mM;
};

void Solve()
{
	FishingKing F;
	printf("%d", F.Fishing());
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}