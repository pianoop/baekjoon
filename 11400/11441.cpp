//합 구하기
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class Seq
{
public:
	Seq()
	{
		solve();
	}

    void Query()
    {
        int m, a, b;
        std::cin>>m;
        
        while(m--)
        {
            std::cin>>a>>b;
            std::cout<<mWin[b]-mWin[a-1]<<"\n";
        }
       
    }

private:
	void solve()
	{
		int n;
		std::cin >> n;
    
        mWin.reserve(n + 1);
		int i = 0, total = 0, tmp;
        mWin.push_back(0);
		for(; i < n; i++)
		{
			std::cin >> tmp;
			total += tmp;
			mWin.emplace_back(total);
		}
	}


private:
	vi mWin;

};

void Solve()
{
	Seq seq;
    seq.Query();
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);

	Solve();

	return 0;
}