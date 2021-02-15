#include<iostream>
#include<vector>

using namespace std;

int func(int ,int);

typedef int (*pfun1)(int,int);
using pfun2 = decltype(func) *;
typedef decltype(func) *pfun3;
using pfun4 = int (*)(int,int);

 inline int add(int a, int b){return a+b;}
 inline int sub(int a, int b){return a-b;}
 inline int mul(int a, int b){return a*b;}
 inline int divc(int a, int b){return b!=0 ? a/b : 0;}

int main()
{
    vector<decltype(func)*> v1{add,sub,mul,divc};

    for(auto f : v1)
    {
        cout << f(2,2) << endl;
    }

    return 0;

}