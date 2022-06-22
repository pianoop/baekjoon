//세 수
//------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v(3);
    for(auto& i : v)
        std::cin>>i;
    
    std::sort(v.begin(), v.end());
    std::cout<< v[1];
    
    
    return 0;
}