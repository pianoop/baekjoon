//버블 소트
//-------------------------------------------------------------------
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Merge
{
public:
	Merge()
	{
		input();
	}

	void Sort()
	{
		merge1(0, mN - 1);
	}

	void PrintAns()
	{
		std::cout << mAns << "\n";
	}

private:
	void input()
	{
		std::cin >> mN;
		mSorting.resize(mN);
		mArr.resize(mN);

		for (auto& a : mArr)
			std::cin >> a;
	}

	void merge1(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			merge1(left, mid);
			merge1(mid + 1, right);

			merge2(left, mid, right);
		}

	}

	void merge2(int left, int mid, int right)
	{
		int s = left, a = left, b = mid + 1;

		while (a <= mid && b <= right)
		{
			if (mArr[a] <= mArr[b])
				mSorting[s++] = mArr[a++];
			else
			{
				mAns += mid - a + 1;
				mSorting[s++] = mArr[b++];
			}
		}

		while (a <= mid)
			mSorting[s++] = mArr[a++];
		while (b <= right)
			mSorting[s++] = mArr[b++];

		std::copy(mSorting.begin() + left, mSorting.begin() + right + 1, mArr.begin() + left);
	}

private:
	int mN;
	long long mAns = 0;
	vi mArr, mSorting;

};



void Solve()
{
	Merge merge;
	merge.Sort();
	merge.PrintAns();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}