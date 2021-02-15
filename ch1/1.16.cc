#include<iostream>

using namespace std;

int main()
{
    cout << "input some numbers" << endl;
    int number , sum = 0;
    while(cin >> number)
    {
        sum += number;
    }
    cout << "the sum = " << sum << endl;
    return 0;
}