//카드 게임
//
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class CardGame
{
public:
	CardGame(int N) :mN(N)
	{
		mCard.resize(mN + 1);
	}

	void Input(int M)
	{
		int tmp;
		while (M--)
		{
			std::cin >> tmp;
			mCard[tmp] = -1;
		}
		tmp = 0;
		for (int i = mN; i > 0; i--)
		{
			if (mCard[i] == -1)
				tmp = i;
			else
				mCard[i] = tmp;
		}
	}

	void PrintAns(int k)
	{
		int tmp;
		while (k--)
		{
			std::cin >> tmp;

			int now = tmp + 1;
			while (mCard[now] != -1)
			{
				now = mCard[now];
			}
			printf("%d\n", now);
			mCard[now] = now + 1;
			mCard[tmp + 1] = now + 1;
		}
	}


private:



private:
	vi mCard;
	int mN;
};

void Solve()
{
	int N, M, K;
	std::cin >> N >> M >> K;

	CardGame game(N);
	game.Input(M);
	game.PrintAns(K);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}