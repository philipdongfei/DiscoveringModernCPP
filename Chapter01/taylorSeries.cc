#include <iostream>

int main(void)
{
    double x= 2.0, xn= 1.0, exp_x= 1.0;
    unsigned long fac = 1;
    for (unsigned long n= 1; n <= 10; ++n) {
        xn *= x;
        fac *= n;
        exp_x += xn / fac;
        std::cout << "e^x is " << exp_x << '\n';
    }

    return 0;
}
