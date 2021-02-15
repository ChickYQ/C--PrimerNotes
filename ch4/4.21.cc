#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v1{1,2,3,4,5,6,7};
    for(auto &n :v1)
    {
        n = ((n%2==0) ? n : n*2);
        cout << n << ",";
    }
    cout << endl;

    return 0;
}