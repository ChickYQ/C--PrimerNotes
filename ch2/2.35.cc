#include<iostream>
#include<typeinfo>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    std::cout << "j is " << typeid(j).name()
             << "\n k is " << typeid(k).name()
             << "\n p is " << typeid(p).name()
             << "\n j2 is " << typeid(j2).name()
             << "\n k2 is " << typeid(k2).name()
             << std::endl;
    
    return 0;
}