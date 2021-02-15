#include"Quote.h"
#include<set>
#include<memory>
using namespace std;

class Basket
{
public:
    Basket() = default;
    void add_item(const Quote& sale);
    void add_item(Quote &&sale);
    double total_receipt() const;

private:
    static bool compare(const shared_ptr<Quote> &p1, const shared_ptr<Quote> &p2)
    {
        return p1 -> isbn() < p2 -> isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

void Basket::add_item(const Quote& sale)
{
    items.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote&& sale)
{
    items.insert(shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt() const
{
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter!=items.cend(); iter = items.upper_bound(*iter))
    {
        int count = items.count(*iter);
        cout << (**iter).isbn() << " : " << count << endl;
        sum += (**iter).net_price(count);
    }
    cout << "Total Sale: " << sum << endl;
    return sum;
}