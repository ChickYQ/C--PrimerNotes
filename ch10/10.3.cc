#include<algorithm>
#include<vector>
#include<iostream>
#include<numeric>
using namespace std;

int main()
{
    vector<int> v1{1,2,3,4};
    cout << accumulate(v1.begin(),v1.end(),0) << endl;

    return 0;
}