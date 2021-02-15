#include<iostream>
#include<deque>
#include<list>

using namespace std;

int main()
{
    list<int> li{1,2,3,4,5,6,7,8,9,10};
    deque<int> d1,d2;
    for(const auto &number : li)
    {
        if(number%2 ==0)
        {
            d2.push_back(number);
        }else
        {
            d1.push_back(number);
        }
        
    }

    cout << "d1:: " ;
    for(const auto &d : d1)
    {
        cout << d << " ";
    }
    cout << endl;

     cout << "d2:: " ;
    for(const auto &d : d2)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}