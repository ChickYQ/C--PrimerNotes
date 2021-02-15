#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;

int main()
{
    vector<pair<string ,int>> v1;
    string buf;
    int n;
    while(cin >>buf >> n)
    {
        v1.push_back(pair<string,int>(buf, n));
    }

    for(const auto &v : v1)
    {
        cout << v.first << " : " << v.second << endl;
    }

    return 0;
}