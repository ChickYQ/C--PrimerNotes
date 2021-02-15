#include<vector>
#include<iostream>
#include<memory>

using namespace std;

template <typename T> class Blob
{
public:
    Blob();
    Blob(initializer_list<T> li):data(make_shared<vector<T>>(li)){}
    size_type size() const {return data -> size();}
    bool empty() const {return data -> empty();}
    void push_back(const T &t1){data -> push_back(t1);}
    void push_back(T &&t1){data -> push_back(std::move(t1));}
    void pop_back();
    T& back();
    T& operator[](size_t i);

private:
    shared_ptr<vector<T>> data;
    void check(size_t i, const string &msg) const;
};

template <typename T> void Blob<T>::check(size_t i, const string &msg) const
{
    if(i >= data -> size())
    {
        throw out_of_range(msg);
    }
}

template <typename T> T& Blob<T>::back()
{
    check(0, "back on empty");
    return data -> back();

}

template <typename T> T& Blob<T>::operator[](size_t i)
{
    check(i, "out of range");
    return (*data)[i];

}