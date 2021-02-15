#include<iostream>
#include<string>
using namespace std;

class Employee{
public:
    Employee():id(++incr),name(""){}
    Employee(const string &s):id(++incr),name(s){}
    Employee(const Employee& epo) = delete;
    Employee& operator=(const Employee& epo) = delete;
private:
    static size_t incr;
    size_t id;
    string name;
};

size_t Employee::incr = 0;
