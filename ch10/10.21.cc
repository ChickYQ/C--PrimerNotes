#include<iostream>

using namespace std;

int main()
{
    int v1 = 12;
    auto la1 = [v1]() mutable -> bool {while(v1!=0){--v1;} return v1 == 0;};
    cout << la1() << endl;
    return 0;
}