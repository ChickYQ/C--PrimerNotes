#include"Quote.h"

int main()
{
    Quote q1{"1",5};
    Bulk_quote b1{"2",6,3,0.6};
    q1.debug();
    b1.debug();

    return 0;
}