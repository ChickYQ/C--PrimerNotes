#include<string>
#include<iostream>

using namespace std;

int main()
{
    string str{"ab2c3d7R4E6"};
    string number{"0123456789"};
    string::size_type pos = 0;
    while(pos!= string::npos)
    {
        pos = str.find_first_of(number, pos);
        if(pos!= string::npos)
        {
            cout << str[pos] << " ";
            ++pos;
        }
    }

    cout << endl;
    pos = 0;
     while(pos!= string::npos)
    {
        pos = str.find_first_not_of(number, pos);
        if(pos!= string::npos)
        {
            cout << str[pos] << " ";
            ++pos;
        }
    }

    return 0;
}