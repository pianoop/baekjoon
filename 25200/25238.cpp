//가희와 방어율 무시
//-------------------------------------------------------------------
#include <iostream>

int main()
{
    int a, b;
    std::cin>> a>> b;
    int c = a*b, d = a*100;
    if(d - c >= 10000)
        std::cout<<0;
    else
        std::cout<<1;
    
    
    
    return 0;
}