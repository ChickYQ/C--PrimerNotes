#include"Sales_data.h"

int main()
{
    Sales_data s1;
    Sales_data s2("1234567");
    Sales_data s3("3214567",3,20.00);
    Sales_data s4(std::cin);

    print(std::cout, s1) << std::endl; 
    print(std::cout, s2) << std::endl;
    print(std::cout, s3) << std::endl;
    print(std::cout, s4) << std::endl;

    return 0;
}