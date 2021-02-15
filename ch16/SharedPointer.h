#include<functional>
#include<iostream>
#include"delete.h"
using namespace std;
using namespace del;

template <typename T> class SharedPointer;
template <typename T> void swap(SharedPointer<T> &lhs,SharedPointer<T> &rhs)
{
    using std::swap;
    cout << "swap =========" << endl;
    swap(lhs.ptr,rhs.ptr);
    swap(lhs.ref_count,rhs.ref_count);
    swap(lhs.deleter,rhs.deleter);
}

template <typename T> class SharedPointer
{
    template <typename X> friend void ::swap(SharedPointer<X> &lhs,SharedPointer<X> &rhs);
public:
    SharedPointer():ptr(nullptr),ref_count(new size_t(1)),deleter(Delete()){}
    explicit SharedPointer(T* raw_ptr):ptr(raw_ptr),ref_count(new size_t(1)),deleter(Delete()){}
    SharedPointer(SharedPointer const& other):ptr(other.ptr),ref_count(other.ref_count),deleter(other.deleter)
    {
        ++*ref_count;
    }
    SharedPointer(SharedPointer && other):ptr(std::move(other.ptr)),ref_count(std::move(other.ref_count)),deleter(std::move(other.deleter))
    {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }
    SharedPointer& operator=(const SharedPointer &other)
    {
        ++*other.ref_count;
        decrement_and_destroy();
        ptr = other.ptr;
        ref_count = other.ref_count;
        deleter = other.deleter;
        return *this;
    }
    SharedPointer& operator=(SharedPointer &&other) noexcept
    {
        ::swap(*this,other);
        other.decrement_and_destroy();
        return *this;
    }
    bool operatorbool() const
    {
        return ptr ? true : false;
    }

    T& operator* () const{
        return *ptr;
    }
    T* operator->() const
    {
        return &*ptr;
    }

    auto use_count() const
    {
        return *ref_count;
    }

    auto get() const
    {
        return ptr;
    }

    auto unique() const
    {
        return 1 == *ref_count;
    }

    auto swap(SharedPointer& rhs)
    {
        ::swap(*this, rhs);
    }

    auto reset()
    {
        decrement_and_destroy();
    }
 
    auto reset(T* pointer)
    {
        if (ptr != pointer)
        {
            decrement_and_destroy();
            ptr = pointer;
            ref_count = new std::size_t(1);
        }
    }

    auto reset(T *pointer, const function<void(T*)> &d)
    {
        reset(pointer);
        deleter = d;
    }

    ~SharedPointer()
    {
        decrement_and_destroy();
    }

private:
    T* ptr;
    size_t* ref_count;
    function<void(T*)> deleter;
    auto decrement_and_destroy()
    {
        if(ptr&&--*ref_count == 0)
        {
            delete ref_count;
            deleter(ptr);
        }else if(!ptr)
        {
           delete ref_count; 
        }
        ref_count = nullptr;
        ptr = nullptr;

    }
};