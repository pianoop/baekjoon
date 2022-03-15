//텀 프로젝트
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Graph
{
public:
	Graph()
	{
		Input();
	}

	void PrintFail()
	{
		if (mNumfail == -1)
			DfsFail();

		printf("%d\n", mNumfail);
	}

private:
	void Input()
	{
		std::cin >> mNumStudents;
		mEdges.resize(mNumStudents +1);
		for (int i = 1; i <= mNumStudents; i++)
			std::cin >> mEdges[i];
	}

	void DfsFail()
	{
		mNumfail = mNumStudents;
		int group = 0;
		std::vector<std::pair<int, int> > checks(mNumStudents+1); //{group,order}

		for (int i = 1; i <= mNumStudents; i++)
		{
			if (checks[i].first == 0)
			{
				int order = 1;
				checks[i].first = ++group;
				checks[i].second = order++;
				int now = i;
				while (true)
				{
					int next = mEdges[now];
					if (checks[next].first == 0)
					{
						checks[next].first = group;
						checks[next].second = order++;
					}
					else if (checks[now].first == checks[next].first)
					{
						mNumfail = mNumfail - order + checks[next].second;
						break;
					}
					else
						break;

					now = next;
				}
			}
		}
	}

private:
	int mNumStudents, mNumfail = -1;
	vi mEdges;
};

void Solve()
{
	Graph termproject;
	termproject.PrintFail();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	int T;
	std::cin >> T;
	while(T--)
		Solve();

	return 0;
}