#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s1, string::size_type sz)
{
    return s1.size() > sz;
}

bool check_size2(const string &s1, string::size_type sz)
{
    return s1.size() < sz;
}

int main()
{
    vector<string> v1;
    string str;
    while(cin >> str)
    {
        v1.push_back(str);
    }

    auto counter = count_if(v1.begin(), v1.end(), bind(check_size, _1 , 5));

    cout << counter << endl;

    vector<int> v2{1,2,3,4,5,6,10,7,8,9};
    string s(6, 'x');

    auto iter = find_if(v2.begin(), v2.end(), bind(check_size2, s, _1));

    cout << *iter << endl;

    return 0;

}