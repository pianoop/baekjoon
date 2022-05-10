//두 동전
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
typedef std::vector<char> vc;
typedef std::vector<int> vi;
typedef std::vector<vc> vvc;

class Poses
{
public:
	int a1, a2, b1, b2, cnt;
};

class Coin
{
public:
	Coin()
	{
		input();
		solve();
	}

	~Coin()
	{
		
	}


private:
	void input()
	{
		memset(mbCheck, false, sizeof(mbCheck));
		
		std::cin >> mN >> mM;
		mMap.resize(mN + 2, vc(mM + 2));

		vi coin;
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				std::cin >> mMap[i][j];
				if (mMap[i][j] == 'o')
				{
					coin.push_back(i);
					coin.push_back(j);
					mMap[i][j] = '.';
				}
			}
		}

		mbCheck[coin[0]][coin[1]][coin[2]][coin[3]] = true;
		mBox.push({ coin[0],coin[1],coin[2],coin[3],0 });
	}

	void solve()
	{
		bool bA, bB;
		int tmpA, tmpB;
		while (!mBox.empty())
		{
			auto [a1, a2, b1, b2, cnt] = mBox.front();
			mBox.pop();

			if (cnt == 10)
				break;
			cnt++;

			//left
			tmpA = a2 - 1, tmpB = b2 - 1;
			if (!mbCheck[a1][tmpA][b1][tmpB])
			{
				bA = false, bB = false;
				mbCheck[a1][tmpA][b1][tmpB] = true;

				if (mMap[a1][tmpA] == '#')
					tmpA = a2;
				else if (mMap[a1][tmpA] == 0)
					bA = true;
				if (mMap[b1][tmpB] == '#')
					tmpB = b2;
				else if (mMap[b1][tmpB] == 0)
					bB = true;

				if (!bA && !bB)
				{
					mbCheck[a1][tmpA][b1][tmpB] = true;
					mBox.push({ a1,tmpA,b1,tmpB,cnt });
				}
				else if (bA != bB)
				{
					mAns = cnt;
					break;
				}
			}

			//right
			tmpA = a2 + 1, tmpB = b2 + 1;
			if (!mbCheck[a1][tmpA][b1][tmpB])
			{
				bA = false, bB = false;
				mbCheck[a1][tmpA][b1][tmpB] = true;

				if (mMap[a1][tmpA] == '#')
					tmpA = a2;
				else if (mMap[a1][tmpA] == 0)
					bA = true;
				if (mMap[b1][tmpB] == '#')
					tmpB = b2;
				else if (mMap[b1][tmpB] == 0)
					bB = true;

				if (!bA && !bB)
				{
					mbCheck[a1][tmpA][b1][tmpB] = true;
					mBox.push({ a1,tmpA,b1,tmpB,cnt });
				}
				else if (bA != bB)
				{
					mAns = cnt;
					break;
				}
			}

			//up
			tmpA = a1 - 1, tmpB = b1 - 1;
			if (!mbCheck[tmpA][a2][tmpB][b2])
			{
				bA = false, bB = false;
				mbCheck[tmpA][a2][tmpB][b2] = true;

				if (mMap[tmpA][a2] == '#')
					tmpA = a1;
				else if (mMap[tmpA][a2] == 0)
					bA = true;
				if (mMap[tmpB][b2] == '#')
					tmpB = b1;
				else if (mMap[tmpB][b2] == 0)
					bB = true;

				if (!bA && !bB)
				{
					mbCheck[tmpA][a2][tmpB][b2] = true;
					mBox.push({ tmpA, a2, tmpB, b2,cnt });
				}
				else if (bA != bB)
				{
					mAns = cnt;
					break;
				}
			}

			//down
			tmpA = a1 + 1, tmpB = b1 + 1;
			if (!mbCheck[tmpA][a2][tmpB][b2])
			{
				bA = false, bB = false;
				mbCheck[tmpA][a2][tmpB][b2] = true;

				if (mMap[tmpA][a2] == '#')
					tmpA = a1;
				else if (mMap[tmpA][a2] == 0)
					bA = true;
				if (mMap[tmpB][b2] == '#')
					tmpB = b1;
				else if (mMap[tmpB][b2] == 0)
					bB = true;

				if (!bA && !bB)
				{
					mbCheck[tmpA][a2][tmpB][b2] = true;
					mBox.push({ tmpA, a2, tmpB, b2,cnt });
				}
				else if (bA != bB)
				{
					mAns = cnt;
					break;
				}
			}
		}

		if (mAns == 0)
			std::cout << "-1";
		else
			std::cout << mAns;
	}


private:
	std::queue<Poses> mBox;
	vvc mMap;
	int mN, mM, mAns;
	bool mbCheck[22][22][22][22];

};

void Solve()
{
	Coin coin;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}