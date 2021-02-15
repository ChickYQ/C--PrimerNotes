#include<string>
#include<iostream>
class Sales_data{

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    
public:

    Sales_data() = default;
    Sales_data(const std::string &s):bookno(s){}
    Sales_data(const std::string &s, unsigned n, double p):bookno(s),units_sold(n),revenue(p*n){}
    Sales_data(std::istream &is)
    {
        double price = 0;
        is >> this -> bookno >> this -> units_sold >> price;
        this -> revenue = this -> units_sold * price;
    }
    std::string isbn() const {return bookno;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:

    std::string bookno;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);