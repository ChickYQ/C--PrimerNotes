#include<iostream>

using namespace std;
template <typename T, unsigned U>

void print(const T (&t1)[U])
{
    for(int i = 0; i<U; i++)
    {
        cout << t1[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[10]{1,2,4,5,6,7,8,9,3};
    string b[3]{"123","456","789"};
    print(a);
    print(b);

    return 0;
}