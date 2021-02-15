#include<memory>
#include<iostream>
using namespace std;
void left_fun(string &lhs, string &rhs)
{
    lhs = "123";
    rhs = "456";
}

void right_fun(int &&lhs, int &&rhs)
{
    allocator<int> alloc;
    auto p(alloc.allocate(3));
    alloc.construct(p, lhs);
    alloc.construct(p+1, 0);
    alloc.construct(p+2, rhs);
    for(auto ptr = p; ptr != p + 3; ++ptr)
    {
        cout << *ptr << endl;
    }
    for(auto ptr = p + 3; ptr != p;)
    {
        alloc.destroy(--ptr);
    }
    alloc.deallocate(p,3);
}

template <typename F, typename T1, typename T2> void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    std::string s1, s2;
    flip(left_fun, s1, s2);
    std::cout << s1 << endl << s2 <<endl;
    flip(right_fun, 1, 2);

    return 0;
}