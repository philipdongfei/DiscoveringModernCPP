#include <iostream>
#include <vector>
#include <complex>
#include "max.h"

/*
template <typename T>
T max (T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}
*/



int main(void)
{
    std::cout << "The maximum of 3 and 5 is " << max(3, 5) << '\n';
    std::cout << "The maximum of 3l and 5l is " << max(3l, 5l) << '\n';
    std::cout << "The maximum of 3.0 and 5.0 is " << max(3.0, 5.0) << '\n';

    unsigned u1 = 2, u2 = 8;
    std::cout << "The maximum of u1 and u2 is " << max(u1, u2) << '\n';
    std::cout << "The maximum of u1*u2 and u1+u2 is " 
              << max(u1*u2, u1+u2) << '\n';

    // dealing with errors in templates
    std::complex<float> z(3, 2), c(4, 8);
    std::cout << "The maximum of c and z is " << ::max(c, z) << '\n';

    vector<std::complex<float>> v;
    sort(v.begin(), v.end());
    return 0;

}
