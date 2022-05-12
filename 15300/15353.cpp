//큰 수 A+B (2)
//-------------------------------------------------------------------
#include <iostream>

class BigInteger
{
public:
	BigInteger()
	{
		input();
	}

	std::string Sum(BigInteger Other)
	{
		std::string Ans;
		int a = int(mNum.length()), b = int(Other.mNum.length()), C = 0;
		if (a < b)
		{
			Ans.resize(b);
			a--, b--;
			while (a >= 0 && b >= 0)
			{
				C = mNum[a] + Other.mNum[b] + C - 96;
				Ans[b] = C % 10 + '0';
				C /= 10;
				a--, b--;
			}

			while (b >= 0)
			{
				C = Other.mNum[b] + C - 48;
				Ans[b] = C % 10 + '0';
				C /= 10;
				b--;
			}
		}
		else
		{
			Ans.resize(a);
			a--, b--;
			while (a >= 0 && b >= 0)
			{
				C = mNum[a] + Other.mNum[b] + C - 96;
				Ans[a] = C % 10 + '0';
				C /= 10;
				a--, b--;
			}

			while (a >= 0)
			{
				C = mNum[a] + C - 48;
				Ans[a] = C % 10 + '0';
				C /= 10;
				a--;
			}
		}
		
		if (C != 0)
		{
			Ans.insert(Ans.begin(), C + '0');
		}

		return Ans;
	}

private:
	void input()
	{
		std::cin >> mNum;
	}

private:
	std::string mNum;
	
};

void Solve()
{
	BigInteger A, B;
	std::cout<< A.Sum(B);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}