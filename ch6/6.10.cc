#include<iostream>

void transfer(int *fi ,int *se)
{
    int temp = *fi;
    *fi = *se;
    *se = temp;
}

int main()
{
    int i = 42;
    int j = 24;
    transfer(&i,&j);
    std::cout << "i= " << i << " j= " << j << std::endl;

    return 0;


}