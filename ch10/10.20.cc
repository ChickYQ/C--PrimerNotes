#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<string> v1;
    string str;
    while(cin >> str)
    {
        v1.push_back(str);
    }

    auto counter = count_if(v1.begin(),v1.end(),[](const string &s1) -> bool {return s1.size()> 6; });
    cout << counter << endl;
    return 0;
}