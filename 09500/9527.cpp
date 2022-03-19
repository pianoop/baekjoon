//1의 개수 세기
//baekjoon algorithm
#include <iostream>
typedef long long ll;

ll FastPow(ll a, int b)
{
	ll ret = 1;
	while (b != 0)
	{
		if (b % 2 != 0)
		{
			ret *= a;
		}
		a *= a;
		b >>= 1;
	}

	return ret;
}

class BinaryOnesNum
{
public:
	BinaryOnesNum() {}

	void InputA()
	{
		std::cin >> mNum;
		mNum--;
	}

	void InputB()
	{
		std::cin >> mNum;
	}

	ll OnesNum()
	{
		if (mAns == -1)
		{
			mAns = 0;
			calc(mNum);
		}
		return mAns;
	}

private:
	void calc(ll now)
	{
		if (now == 0)
			return;

		ll temp = now;
		int n = 0;

		while (temp != 0)
		{
			temp = temp >> 1;
			n++;
		}
		n--;
		temp = FastPow(2, n);
		now -= temp;
		mAns += temp / 2 * n + now + 1;

		calc(now);
	}

private:
	ll mNum= 0;
	ll mAns = -1;
};

void Solve()
{
	BinaryOnesNum A, B;
	A.InputA();
	B.InputB();

	printf("%lld", B.OnesNum() - A.OnesNum());
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}