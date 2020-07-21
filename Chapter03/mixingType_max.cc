#include <iostream>
#include "max.h"


int main()
{
    unsigned u1 = 2;
    int i = 3;
    //std::cout << "The maximum of u1 and i is " << max(u1, i) << '\n';//Error: no match
    std::cout << "max of u1 and i is " << max(int(u1), i) << '\n';
    std::cout << "max of u1 and i is " << max<int>(u1, i) << '\n';
}
