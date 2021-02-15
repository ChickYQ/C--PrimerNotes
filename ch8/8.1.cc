#include<iostream>
#include<string>

std::istream& read_and_print(std::istream &is)
{
    auto old_state = is.rdstate();
    is.clear();
    std::string str;
    is >> str;
    std::cout << str;
    is.setstate(old_state);

    return is;
}

int main()
{
    std::string str;
    read_and_print(std::cin) >> str;
    std::cout << str;

    return 0;
}