#include<iostream>
#include<cctype>
#include<string>
using namespace std;
bool is_upper(const string &str)
{
    for(auto ch : str)
    {
        if(isupper(ch))
        return true;
    }
    return false;
}

void to_lower(string &str)
{
    for(auto &ch : str)
    {
        if(isupper(ch))
        ch = tolower(ch);
    }
}

int main()
{
    string a("ahcYUFhlo");
    cout << is_upper(a) << endl;
    to_lower(a);
    cout << a << endl;

    return 0;
}