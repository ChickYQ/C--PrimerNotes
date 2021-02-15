#include"Quote.h"
using namespace std;

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &s, double p, std::size_t min, double count):Quote(s,p),min_qty(min),discount(count){}
    double net_price(std::size_t n) const =0;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Culk_quote : public Disc_quote
{
public:
     Culk_quote(const std::string &s, double p, std::size_t min, double count):Disc_quote(s,p,min,count){}
     double net_price(std::size_t n) const override
     {
         return n * 0.9 * price;
     }
};