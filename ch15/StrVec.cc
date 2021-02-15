#include"StrVec.h"
allocator<string> StrVec::alloc; 
 StrVec::StrVec(initializer_list<string> list):StrVec()
 {
     auto data = alloc_n_copy(list.begin(),list.end());
     elements = data.first;
     first_free = cap = data.second;

 }

 StrVec::StrVec(StrVec &&str) noexcept :elements(str.elements),first_free(str.first_free)
 ,cap(str.cap)
 {
     str.first_free = str.elements = str.cap = nullptr;
 }

 StrVec& StrVec::operator=(StrVec &&str) noexcept
 {
     if(this != &str)
     {
         free();
         elements = str.elements;
         first_free = str.first_free;
         cap = str.cap;
         str.elements = str.first_free = str.cap = nullptr;
     }

     return *this;
 }

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}
pair<string*,string*> StrVec::alloc_n_copy(const string* b, const string* d)
{
    auto data = alloc.allocate(d-b);
    return {data, uninitialized_copy(b,d,data)};

}

void StrVec::free()
{
    if(elements)
    {
        for(auto p = first_free; p != elements;)
        {
            alloc.destroy(--p);
        }
    alloc.deallocate(elements ,cap - elements);
    }
}

StrVec::StrVec(const StrVec& str)
{
    auto data = alloc_n_copy(str.begin(), str.end());
    elements = data.first;
    first_free = cap = data.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& str)
{
    auto data = alloc_n_copy(str.begin(), str.end());
    free();
    elements = data.first;
    first_free = cap =data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i!=size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}