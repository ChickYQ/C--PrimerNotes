#include"Basket.h"

int main()
{
    Quote q1("1",2);
    Quote q2("1",2);
    Bulk_quote q3("2",4,1,0.7);
    Bulk_quote q4("3",4,2,0.7);
    Quote q5("4",2);
    Basket basket;
    basket.add_item(q1);
    basket.add_item(q2);
    basket.add_item(q3);
    basket.add_item(q4);
    basket.add_item(q5);

    basket.total_receipt();

    return 0;
}