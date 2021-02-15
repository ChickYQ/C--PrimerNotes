#include"Person.h"

Person::Person(std::istream &is)
{
    read(is,*this);
}

std::istream &read(std::istream &is, Person &person){
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os,const Person &person){
    return os << person.name << " " << person.address;
}