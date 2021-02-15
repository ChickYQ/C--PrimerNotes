#include<list>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    list<char *> l1{"123","456","789"};
    vector<string> v1;
    v1.assign(l1.cbegin(),l1.cend());

    for(const auto &v :v1)
    {
        cout << v << endl;
    }

    return 0;
}