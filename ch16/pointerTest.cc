#include <iostream>
#include <string>
#include "SharedPointer.h"

int main()
{
    auto foo = SharedPointer<int>{ new int(42) };
    auto foo2= SharedPointer<int>{ new int(42) };
    auto bar(foo) ;
    std::cout << *foo << std::endl;
    std::cout << foo.use_count() << std::endl;
    bar = std::move(foo2);
    auto string_ptr = SharedPointer<std::string>{ new std::string{ "Yue" } };
    std::cout << *string_ptr << std::endl;
    std::cout << string_ptr->size() << std::endl;

    return 0;
}