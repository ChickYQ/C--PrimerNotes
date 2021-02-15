#include<iterator>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    string filename{"./123.txt"};
    ifstream ifs(filename);
    vector<string> v1;
    istream_iterator<string> is(ifs),eof;
    while(is != eof)
    {
        v1.push_back(*is++);
    }

    for(auto &v : v1)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}