#include<iostream>
#include<string>


class Person{

   friend std::istream& read(std::istream &is, Person &person);
   friend std::ostream& print(std::ostream &os, const Person &person);

public:
    Person() = default;
    Person(const std::string &sname):name(sname){}
    Person(const std::string &sname,const std::string &saddress):name(sname),address(saddress){}
    Person(std::istream &is);

    const std::string& getName() {return name;}
    const std::string& getAddress() {return address;}

private:
    std::string name;
    std::string address;
   
};

std::istream& read(std::istream &is, Person &person);
std::ostream& print(std::ostream &os, const Person &person);

