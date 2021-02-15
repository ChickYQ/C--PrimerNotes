#include<iterator>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v1(istream_iterator<int>(std::cin),istream_iterator<int>());
    sort(v1.begin(),v1.end());
    unique_copy(v1.begin(),v1.end(),ostream_iterator<int>(std::cout, " "));

    return 0;
}