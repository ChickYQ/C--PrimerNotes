#include<iostream>
#include"Quote.h"
using namespace std;
void Quote::debug() const
{
    cout << bookno << " " << price; 
}

double Bulk_quote::net_price(size_t n) const
{
    if(n >= min_qty)
        return n * (1-discount) * price;
    else
    {
        return n * price;
    }
     
}

 void Bulk_quote::debug() const {
     Quote::debug();
     cout << " " << min_qty << " " << discount;
 }