#include<iostream>
#include<string>
using namespace std;
class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
    HasPtr(const string &s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    HasPtr(const HasPtr& ori):ps(ori.ps),i(ori.i),use(ori.use){
        ++*use;
    }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr()
{
    --*use;
    if(*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& ori)
{
    ++*ori.use;
    if(--*use == 0)
    {
        delete ps;
        delete use;
    } 
    ps = ori.ps;
    use = ori.use;
    i =ori.i;

    return *this;
}

inline void swap(HasPtr &h1, HasPtr &h2)
{
    cout << "start swap " << endl;
    using std::swap;
    swap(h1.ps, h2.ps);
    swap(h1.i, h2.i);
}