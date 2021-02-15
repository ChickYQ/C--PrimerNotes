#include<memory>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    allocator<int> alloc;
    vector<int> v1{1,2,3};
    auto p = alloc.allocate(v1.size()*2);
    auto q = uninitialized_copy(v1.begin(),v1.end(),p);
    cout << *--q << endl;
    ++q;
    uninitialized_fill_n(q, v1.size(), 5);
    cout << *q << endl;
    return 0;
}