#include "complex.h"
#include <iostream>

int main()
{
    complex cc(7.0, 8.0), c2= {0,1}, c3={9.3}, c4(cc);
    std::cout << "cc + c4 is " << cc + c4 << std::endl;

    std::cout << "cc = " << cc << '\n';
    std::cout << "c2 = " << c2 << '\n';
    std::cout << "c3 = " << c3 << '\n';
    std::cout << "c4 = " << c4 << '\n';


    std::cout << "c3 - c2 = " << c3 - c2 << '\n';

    double r2 = real(complex(3, 7)) * 2.0;
    std::cout << "r2 = " << r2 << '\n';

    return 0;

}
