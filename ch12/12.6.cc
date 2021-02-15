#include<iostream>
#include<vector>
#include<memory>

using namespace std;
using Iter = vector<int> *;
Iter build_vector()
{
    return new vector<int>;
}

Iter read_vec(Iter it)
{
    int n;
    while(cin >>n)
    {
        it -> push_back(n);
    }

    return it;
}

void print(Iter it)
{
    for(auto &i : *it)
    {
        cout << i << endl;
    }
}

int main()
{
    Iter it = read_vec(build_vector());
    print(it);
    delete it;

    return 0;
}