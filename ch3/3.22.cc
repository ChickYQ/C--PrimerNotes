#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int main()
{
    vector<string> text;
    for(string line;getline(cin,line);text.push_back(line));
    for(auto it = text.begin();it != text.end()&&!it->empty();++it)
    {
        for(auto &c :*it)
        {
            if(isalpha(c))
            c = toupper(c);
        }
        cout << *it << endl;
    }
    return 0;
}