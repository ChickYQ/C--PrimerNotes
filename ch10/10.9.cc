#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool isShorter(const string& s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool is_length_five(const string& s1)
{
    return s1.size() >= 5;
}

int main()
{
    vector<string> v1;
    string str;
    while(cin >> str)
    {
        v1.push_back(str);
    }

    sort(v1.begin(),v1.end());

    for(auto &v : v1){cout << v << " ";}
    cout << endl;

    auto unique_it = unique(v1.begin(),v1.end());
    v1.erase(unique_it,v1.end());

    for(auto &v : v1){cout << v << " ";}
    cout << endl;

    stable_sort(v1.begin(),v1.end(),isShorter);
    for(auto &v : v1){cout << v << " ";}
    cout << endl;

    auto it = partition(v1.begin(),v1.end(),is_length_five);
    for(auto iter = v1.begin();iter != it; ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    return 0;


}