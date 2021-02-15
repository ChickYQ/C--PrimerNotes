#include<iostream>
#include<vector>

using namespace std;

bool is_prefix(vector<int> const& v1, vector<int> const& v2)
{
    if(v1.size()>v2.size())
    {
        return is_prefix(v2,v1);
    }

    for(decltype(v1.size()) i = 0;i<v1.size();++i)
    {
        if(v1[i] != v2[i])
        return false;  
    }
     return true;
}
int main()
{
    vector<int> v1{0,1,1,2},v2{0,1,1,2,3,5,8},v3{0,1,1,3,6};

    cout << is_prefix(v1,v2) << endl;
    cout << is_prefix(v3,v2) << endl;
    return 0;
    
}