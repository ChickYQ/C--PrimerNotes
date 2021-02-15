#include<iostream>
#include<string>

using namespace std;

void read_word();
void read_line();

int main()
{
    cout << "read word from input stream: " << endl;
    read_word();
    getchar();
    cout << "read line from input stream" << endl;
    read_line();
    
    return 0;
}

void read_word()
{
    string str;
    while(cin >> str)
    {
        cout << str << endl;
    }

}

void read_line()
{
    string str;
    while(getline(cin,str))
    {
        cout << str << endl;
    }
}