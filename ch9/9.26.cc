#include<vector>
#include<list>
#include<iostream>

using namespace std;

int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> v1;
    list<int> l1;
    for(const auto &num : ia)
    {
        v1.push_back(num);
        l1.push_back(num);
    }

    for(auto it = v1.cbegin();it!=v1.cend();)
    {
        if((*it)%2 == 0)
        {
            it = v1.erase(it);
        }else
        {
            ++it;
        }
        
    }

    for(auto it = l1.cbegin();it!=l1.cend();)
    {
        if((*it)%2 != 0)
        {
            it = l1.erase(it);
        }else
        {
            ++it;
        }
    }

    for(auto it = l1.cbegin();it!=l1.cend();++it)
    {
        cout << *it << endl;
    }

    cout <<  endl;
    cout <<  endl;

     for(auto it = v1.cbegin();it!=v1.cend();++it)
    {
        cout << *it << endl;
    }

    return 0;
}