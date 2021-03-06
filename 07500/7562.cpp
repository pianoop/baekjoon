//나이트의 이동
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int nextx[8] = { 2, 2, 1, 1, -2, -2, -1, -1 };
int nexty[8] = { 1, -1, 2, -2, 1, -1, 2, -2 };

class Pos2
{
public:
	int x, y;

	Pos2(int a, int b) :x(a), y(b) {}
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;

		vvi map(N, vi(N));
		int x0, y0, xf, yf;
		std::cin >> x0 >> y0 >> xf >> yf;
		map[x0][y0] = 1;
		std::queue<Pos2> box;
		box.push(Pos2(x0, y0));
		int x, y;
		while (!box.empty())
		{
			x = box.front().x, y = box.front().y;
			if (x == xf && y == yf)
			{
				std::cout << map[x][y] - 1 << "\n";
				break;
			}

			for (int nx, ny, i = 0;i < 8;i++)
			{
				nx = x + nextx[i], ny = y + nexty[i];
				if (nx >= N || nx < 0 || ny >= N || ny < 0)
					continue;
				else if (map[nx][ny] == 0)
				{
					map[nx][ny] = map[x][y] + 1;
					box.push(Pos2(nx, ny));
				}
			}

			box.pop();
		}
	}

	return 0;
}