#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class HasPtr{
friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &ori)
    {
        ps = new string(*(ori.ps));
        i = ori.i;
    }
    ~HasPtr(){
        delete ps;
    }
    const string& get_string() const {
        return *ps;
    }
    void set_string(const string &str)
    {
        *ps = str;
    }
    HasPtr& operator=(const HasPtr &ori)
    {
        auto new_ps = new string(*(ori.ps));
        delete ps;
        ps = new_ps;
        i = ori.i;
        return *this;
    }
    bool operator<(const HasPtr &h1)
    {
        return *ps < *h1.ps;
    }
    void swap(HasPtr &rhs) 
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }
private:
    string *ps;
    int i;
};
inline void swap(HasPtr &h1, HasPtr &h2)
{
    cout << "start swap " << endl;
    using std::swap;
    swap(h1.ps, h2.ps);
    swap(h1.i, h2.i);
}

int main()
{
    HasPtr pt1("123");
    HasPtr pt2("456");
    HasPtr pt3("4567");
    HasPtr pt4("12");
    swap(pt1,pt2);
    vector<HasPtr> v1{pt1,pt2,pt3,pt4};
    sort(v1.begin(),v1.end());
    for(auto &v : v1)
    {
        cout << v.get_string() << endl;
    }

    //cout << pt2.get_string() << endl;
    //pt2.set_string("111");
   // cout << pt1.get_string() << endl;
    //cout << pt2.get_string() << endl;
    //pt2 = pt1;
    //cout << pt2.get_string() << endl;

    return 0;
}