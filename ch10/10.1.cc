#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string str;
    int num;
    vector<int> v1;
    list<string> l1;
    while (cin >> num)
    {
        v1.push_back(num);
    }

    cout << count(v1.begin(),v1.end(),2) << endl;
    
    cin.clear();

    while (cin >> str)
    {
        l1.push_back(str);
    }

    cout << count(l1.begin(),l1.end(),"123") << endl;

    return 0;
    
}