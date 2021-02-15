#include<string>
#include<iostream>
using namespace std;
class Quote
{
public:
    Quote() = default;
    Quote(const std::string &s, double p):bookno(s),price(p){}
    Quote(const Quote& q):bookno(q.bookno),price(q.price){cout << "quote copy con" << endl;}
    Quote(Quote&& q):bookno(std::move(q.bookno)),price(std::move(q.price)){cout << "quote move con" << endl;}
    Quote& operator=(const Quote& q){bookno = q.bookno;price = q.price;cout << "quote copy = " << endl;return *this;}
    Quote& operator=(Quote&& q){bookno = std::move(q.bookno);price = std::move(q.price);cout << "quote move = " ;return *this;}
    std::string isbn() const {return bookno;}
    virtual double net_price(std::size_t n) const {return n * price;}
    virtual ~Quote() = default;
    virtual void debug() const;
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
private:
   std::string bookno;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote{

public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double p, std::size_t min, double count):Quote(s,p),min_qty(min),discount(count){cout << "bulk con" << endl;}
    Bulk_quote(const Bulk_quote& q):Quote(q),min_qty(q.min_qty),discount(q.discount){cout << "bulk copy con" << endl;}
    Bulk_quote(Bulk_quote&& q):Quote(q),min_qty(std::move(q.min_qty)),discount(std::move(q.discount)){cout << "bulk move con " << endl;} 
    Bulk_quote& operator=(const Bulk_quote& q){
        Quote::operator=(q);
        min_qty = q.min_qty;
        discount = q.discount;
        cout << "bulk copy =" << endl;}
    Bulk_quote& operator=(Bulk_quote&& q){
        Quote::operator=(q);
        min_qty = std::move(q.min_qty);
        discount = std::move(q.discount);
        cout << "bulk move =" << endl;}
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
    ~Bulk_quote() = default;
    double net_price(std::size_t n) const override;
    void debug() const override;
private:
    std::size_t min_qty;
    double discount = 0.0;
};