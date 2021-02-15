#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<memory>
#include<fstream>

using namespace std;

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
public:
    StrBlob():data(make_shared<vector<string> >()){}
    StrBlob(const initializer_list<string> &li):data(make_shared<vector<string>>(li)){}
    vector<string>::size_type size() const {return data -> size();}
    std::string& front();
    std:: string& back();
    void push_back(const string &str){data -> push_back(str);}
    void pop_back(){data -> pop_back();}
    bool empty(){return data -> empty();}
    shared_ptr<vector<string>>& get_data()
    {
        return data;
    }
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(vector<string>::size_type i, const string &msg) const{
        if(i >= data -> size())
        {
            throw out_of_range(msg);
        }
    }
};

string& StrBlob::front()
{
    check(0,"front on empty strblob");
    return data -> front();
}
string& StrBlob::back()
{
    check(0,"back on empty strblob");
    return data -> back();
}

class StrBlobPtr{

public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &st,  vector<string>::size_type index = 0):wptr(st.data),curr(index){}
    string& deref() const
    {
        auto ptr = check();
        return (*ptr)[curr];
    }
    StrBlobPtr& incr()
    {
        check();
        ++curr;
        return *this;
    }
private:
    vector<string>::size_type curr;
    weak_ptr<vector<string>> wptr;
    shared_ptr<vector<string>> check() const {
        if(!wptr.lock())
        {
            throw runtime_error("ptr unbound");
        }
        if(curr >= wptr.lock() -> size())
        {
            throw out_of_range("out of range");
        }

        return wptr.lock();
    }
};

StrBlobPtr StrBlob::begin()
    {
        return StrBlobPtr(*this);
    }
StrBlobPtr StrBlob::end()
    {
        return StrBlobPtr(*this, data -> size());
    }
int main()
{
   /* StrBlob b1;
    {
        StrBlob b2{"1", "2", "3", "4"};
        b1 = b2;
        b2.push_back("5");
    }

    auto data = b1.get_data();
    for(auto &d :*data)
    {
        cout << d << endl;
    }*/
    string filename ="./123.txt";
    ifstream ifs(filename);
    StrBlob b1;
    string str;
    while(getline(ifs,str))
    {
        b1.push_back(str);
    }

    StrBlobPtr ptr(b1);
    while(true)
    {
        cout << ptr.deref() << endl;
        ptr.incr();
    }
    return 0;

}