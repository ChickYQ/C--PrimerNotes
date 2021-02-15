#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    vector<int> v1{2,4,6,8};
    int i = 2;
    modulus<int> mod;
    auto iter = find_if_not(v1.begin(),v1.end(),[&](int s){return mod(s,i)==0;});
    cout << (iter == v1.end() ? "yes" : "no") << endl;
    i=4;
    iter = find_if_not(v1.begin(),v1.end(),[&](int s){return mod(s,i)==0;});
    cout << (iter == v1.end() ? "yes" : "no") << endl;
}