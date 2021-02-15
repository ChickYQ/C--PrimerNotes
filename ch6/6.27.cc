#include<iostream>
#include<initializer_list>

using namespace std;

int sum(initializer_list<int> list)
{
    int res = 0;
    for(const auto &num : list)
    {
        res += num;
    }

    return res;
}

int main()
{
    cout << "the summary is " << sum({1,2,3,4,5}) << endl;

    return 0;
}