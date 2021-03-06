//미세먼지 안녕!
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int > vi;
typedef std::vector<vi> vvi;

int R, C;
int clear[2] = { -1,-1 };
int ny[4] = { 1,-1,0,0 }, nx[4] = { 0,0,1,-1 };

bool Check(const int& i, const int& j, const vvi& map)
{
	return (i >= 0 && j >= 0 && i < R && j < C && map[i][j] != -1);
}

vvi Spread(const vvi& room)
{
	vvi after = room;

	for (int i = 0;i < R;i++)
	{
		for (int spr, j = 0;j < C;j++)
		{
			if (room[i][j] > 0)
			{
				spr = room[i][j] / 5;
				for (int nn, nm, k = 0;k < 4;k++)
				{
					nn = i + ny[k], nm = j + nx[k];
					if (Check(nn, nm, room))
					{
						after[i][j] -= spr;
						after[nn][nm] += spr;
					}
				}
			}
		}
	}

	return after;
}

void Circulate(vvi& room)
{
	int copy = room[clear[0]][1];   //위 반시계방향
	for (int tmp, j = 2;j < C;j++)
	{
		tmp = room[clear[0]][j];
		room[clear[0]][j] = copy;
		copy = tmp;
	}
	C--;							    // { 주의1!
	for (int tmp, i = clear[0] - 1; i >= 0;i--)
	{
		tmp = room[i][C];
		room[i][C] = copy;
		copy = tmp;
	}
	for (int tmp, j = C - 1;j >= 0;j--)
	{
		tmp = room[0][j];
		room[0][j] = copy;
		copy = tmp;
	}
	for (int tmp, i = 1;i < clear[0] ;i++)
	{
		tmp = room[i][0];
		room[i][0] = copy;
		copy = tmp;
	}
	C++;								  // 주의1! }  (C복구)


	copy = room[clear[1]][1];			  //아래 시계방향
	for (int tmp, j = 2;j < C;j++)
	{
		tmp = room[clear[1]][j];
		room[clear[1]][j] = copy;
		copy = tmp;
	}
	C--;								   // { 주의1!
	for (int tmp, i = clear[1] + 1; i < R; i++)
	{
		tmp = room[i][C];
		room[i][C] = copy;
		copy = tmp;
	}
	R--;								    // { 주의2!
	for (int tmp, j = C - 1;j >= 0;j--)
	{
		tmp = room[R][j];
		room[R][j] = copy;
		copy = tmp;
	}
	for (int tmp, i = R - 1;i > clear[1] ;i--)
	{
		tmp = room[i][0];
		room[i][0] = copy;
		copy = tmp;
	}
	R++;C++;									 // 주의1, 2 }} (RC복구)

	room[clear[0]][1] = room[clear[1]][1] = 0;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int T;
	std::cin >> R >> C >> T;

	vvi room(R, vi(C));
	for (int i = 0;i < R;i++)
	{
		for (int j = 0;j < C;j++)
		{
			std::cin >> room[i][j];
			if (room[i][j] == -1)
			{
				if (clear[0] != -1)
					clear[1] = i;
				else
					clear[0] = i;
			}
		}
	}

	while (T--)
	{
		room = Spread(room);
		Circulate(room);
	}

	room[clear[0]][0] = room[clear[1]][0] = 0;
	int ans = 0;
	for (auto& a : room)
		for (auto& b : a)
			ans += b;

	std::cout << ans;

	return 0;
}