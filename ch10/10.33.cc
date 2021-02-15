#include<iterator>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
    ifstream ifs("./num.txt");
    istream_iterator<int> is(ifs),eof;
    ofstream of1("./num1.txt",ofstream::app);
    ofstream of2("./num2.txt",ofstream::app);
    ostream_iterator<int> os1(of1, " "),os2(of2, " ");
    while(is != eof)
    {
        auto tmp = *is++;
        tmp&0x1 ? os1 = tmp : os2 = tmp;
    }

    return 0;
}