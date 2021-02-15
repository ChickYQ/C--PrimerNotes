#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
    string str;
    string result = "";
    while(getline(cin,str))
    {
        for(auto &c : str)
        {
            if(!ispunct(c))
            {
                result += c;
            }
        }

        cout << result << endl;
    }

    return 0;
}