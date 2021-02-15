#include<iostream>
#include<deque>
#include<list>
#include<string>

using namespace std;

int main()
{
    string buf;
    deque<string> dq;
    list<string> li;

    while(cin >> buf)
    {
        dq.push_back(buf);
        li.push_back(buf);
    }

    for(auto it = dq.cbegin();it!=dq.cend();++it)
    {
        cout << *it << endl;
    }

    cout << endl << endl;

     for(auto it = li.cbegin();it!=li.cend();++it)
    {
        cout << *it << endl;
    }


}