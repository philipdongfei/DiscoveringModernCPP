#include <iostream>
#include "complex.h"



int main()
{
    complex c1(3.0, 2.0), c2,
            c3(c1), //copy
            c4{c1}, //c++11:  non-narrowing
            z1,
            z2(), // error: trap;
            z3(4), // z3(4.0, 0.0)
            z4=4, // z4(4.0, 0.0)
            z5(0, 1);
    std::cout << "z3: " << z3.get_r() << "," << z3.get_i() << std::endl;
    real(z4) += 5;
    std::cout << "z4: " << z4.get_r() << "," << z4.get_i() << std::endl;

    //double r2 = real(complex(3.0, 7.0)) * 2.0;  // okay!
    const double &rr = real(complex(3.0, 7.0)); // Really bad!!!
    std::cout << "The real part is " << rr << '\n';
    // set c1
    /*
    c1.set_r(3.0);   // Clumsy init
    c1.set_i(2.0); 
    */

    // copy c1 to c2
    c2.set_r(c1.get_r());   // Clumsy copy
    c2.set_i(c1.get_i());

    return 0;
}
