#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
    for(int i,j;cout << "input two number"<< endl,cin >> i >> j;)
    {
        try
        {
            if(j == 0)
              throw runtime_error("div is 0");

            cout << i/j << endl;
            

        }
        catch(runtime_error err)
        {
            std::cerr << err.what() << "try angin y or n" << '\n';
            char ch;
            cin >> ch;

            if(!cin||ch == 'n')
                break;
        }
        
    }

    return 0;
}