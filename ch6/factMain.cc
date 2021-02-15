#include<iostream>
#include"fact.h"

int main()
{
    for(size_t i =0 ;i <=5;++i)
    {
        std::cout << func(i) << std::endl;
    }

    return 0;
}