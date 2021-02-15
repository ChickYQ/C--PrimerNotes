#include<forward_list>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    forward_list<int> li{1,2,3,4,5,6,7};
    auto prev = li.cbefore_begin();
    auto curr = li.cbegin();
    for(;curr!=li.cend();)
    {
        if((*curr)&0x1)
        {
            curr = li.erase_after(prev);
        }else
        {
            prev = curr;
            ++curr;
        }
        
    }

    for(auto &num : li)
    {
        cout << num << endl;
    }

    return 0;
}