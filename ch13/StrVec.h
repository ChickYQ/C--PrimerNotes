#include<memory>
#include<string>
#include<iostream>
using namespace std;

class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(initializer_list<string> list);
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& StrVec::operator=(StrVec &&str) noexcept;
    ~StrVec();
    void push_back(const string&);
    void push_back(string &&);
    size_t size(){return first_free - elements;}
    size_t capacity(){return cap - elements;}
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;
    pair<string*,string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_n_alloc(){if(size() == capacity())reallocate();}
    void reallocate();
};