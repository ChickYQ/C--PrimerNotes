#include<iterator>
#include<vector>
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v1{1,2,3,3,4,5,2,5,6,7,8,9,0,8};
    list<int> l1;
    sort(v1.begin(), v1.end());
    unique_copy(v1.begin(), v1.end(), back_inserter(l1));

    for(auto a : l1)
    {
        cout << a << " " ;
    }
    cout << endl;

    return 0;
}