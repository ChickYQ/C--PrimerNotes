#include<iostream>
#include<vector>

using namespace std;

void print_vec(vector<int> &v1)
{
    #ifndef NDEBUG
        cout <<__FILE__ << " in function " << __func__ << " at line " << __LINE__ << endl
             << "compiled on " << __DATE__ << " at " << __TIME__ <<endl;
    #endif

    for(auto num : v1)
    {
        cout << num << endl;
    }
}
int main()
{
    vector<int> v1{1,2,3,4,5};
    print_vec(v1);

    return 0;
}