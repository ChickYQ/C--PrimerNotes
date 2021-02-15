#include<iostream>

template <typename T>

bool compare(const T &t1, const T &t2)
{
    return t1 < t2;
}

int main()
{
    int a = 3, b = 4;
    double c = 2.5, d = 1.6;

    std::cout << compare(a,b) << std::endl;
    std::cout << compare(c,d) << std::endl;
}