//아기 상어
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Pos
{
public:
	int n, m, step;

	Pos(int a,int b, int c):n(a),m(b),step(c){}
	~Pos() {}

	bool operator<(const Pos b) const
	{
		if (this->step == b.step)
		{
			if (this->n == b.n)
			{
				return this->m > b.m;
			}
			return this->n > b.n;
		}
		return this->step > b.step;
	}
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	vvi check(N, vi(N));
	vvi space(N, vi(N));
	std::priority_queue<Pos> Box;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			std::cin >> space[i][j];
			if (space[i][j] == 9)
			{
				Box.push(Pos(i, j, 1));
				check[i][j] = 1;
				space[i][j] = 0;
			}
		}
	}

	int Nn[4] = {-1,0,0,1};
	int Nm[4] = {0,-1,1,0};
	int size = 2, eat=0, second = 0,Min=10000;
	while (!Box.empty())
	{
		int n = Box.top().n, m = Box.top().m, step=Box.top().step;
		if (step > Min)
		{
			if (space[n][m]!=0 && space[n][m] < size)
			{
				second += step-1;
				space[n][m] = 0;
				eat++;
				if (eat == size)
				{
					size++;
					eat = 0;
				}
				while (!Box.empty())
				{
					Box.pop();
				}
				vvi(N, vi(N)).swap(check);
				check[n][m] = 1;
				Min = 10000;
				Box.push(Pos(n, m, 1));
			}
			else
			{
				Box.pop();
			}
			continue;
		}

		for (int nn,nm, i = 0;i < 4;i++)
		{
			nn = n + Nn[i], nm = m + Nm[i];
			if (nn >= N || nn < 0 || nm >= N || nm < 0)
				continue;

			if (check[nn][nm] == 0)
			{
				if (space[nn][nm]==0 || space[nn][nm]==size)
				{
					Box.push(Pos(nn, nm,step+1));
					check[nn][nm] =  1;
				}
				else if (size < space[nn][nm])
				{
					check[nn][nm] = 1;
				}
				else 
				{
					Min = step;
					check[nn][nm] = 1;
					Box.push(Pos(nn, nm, step + 1));
				}
			}
		}

		Box.pop();
	}

	std::cout << second;

	return 0;
}