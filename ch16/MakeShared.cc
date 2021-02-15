#include <iostream>
#include <memory>
#include <string>
using namespace std;
template<typename T, typename... Args> auto Make_Shared(Args&&...args) -> shared_ptr<T>
{
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
} 
struct a1
{
    a1(int aa,const string &ss):a(aa),s(ss){}
    int a;
    string s;
};
int main(){
    cout << *(Make_Shared<int>(42));
    auto a = Make_Shared<a1>(3,string("456"));
    cout << a -> s << endl;
    return 0;
}