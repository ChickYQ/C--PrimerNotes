#include<iostream>
#include<string>

using namespace std;

string c_equal(string a, string b);
string c_size(string a, string b);

int main()
{
    string a,b;
    cout << "input two string ,separated by enter" << endl;
    while(getline(cin,a)){
        getline(cin,b);
        cout << c_equal(a,b) << endl;
        cout << c_size(a,b) << endl;
    }

    return 0;
}

string c_equal(string a ,string b)
{
    string result;
    if(a!=b)
    {
        if(a<b)
        {
            result = "large string is " + b;
        }else
        {
             result = "large string is " + a;
        }
        
    }else
    {
        result = "a == b";
    }
    return result;
    
}

string c_size(string a ,string b)
{
    string result;
    if(a.size()!=b.size())
    {
        if(a.size()<b.size())
        {
            result = "large size string is " + b;
        }else
        {
            result = "large size string is " + a;
        }
        
    }else
    {
        result = "a == b";
    }
    return result;
    
}