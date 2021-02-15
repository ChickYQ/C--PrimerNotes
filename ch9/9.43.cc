#include<string>
#include<iostream>

using namespace std;

void replace_string(string &s1 , const string &s2, const string &s3)
{
    auto in = s1.find(s2) ;
    if(in != string::npos)
    {
        s1.replace(in,s3.size(),s3);
    }
}

int main()
{
    string s1 = "th123456tho789123456";
    string s2 = "tho";
    string s3 = "though";

    replace_string(s1,s2,s3);

    cout << s1 << endl;

    return 0;
}