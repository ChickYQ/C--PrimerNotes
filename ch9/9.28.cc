#include<forward_list>
#include<string>
#include<iostream>

using namespace std;

void insert_list(forward_list<string> &li, const string &s1, const string &s2)
{
    for(auto it = li.cbegin();it != li.cend();++it)
    {
        if(*it == s1)
        {
            it = li.insert_after(it,s2);
        }
    }
}

int main()
{
    forward_list<string> li{"12","1234","yui","qwer","111"};
    insert_list(li, "yui", "222");

    for(const auto &n: li)
    {
        cout << n << endl;
    }

    return 0;
}