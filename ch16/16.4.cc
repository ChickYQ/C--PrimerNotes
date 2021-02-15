#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <typename T, typename U>

T find_v(const T &begin, const T &end, const U &target)
{
    T index;
    for(index = begin; index != end; ++index)
    {
        if(*index == target)
        {
            break;
        }
    }
    return index;
}

int main()
{
    vector<int> v1{1,2,4,5,6,7,8};
    string s1{"chickyq"};
    cout << *(find_v(v1.begin(),v1.end(),5)) << endl;
    cout << *(find_v(s1.begin(),s1.end(),'k')) << endl;
    return 0;
}