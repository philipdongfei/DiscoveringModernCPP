#include <iostream>
#include <string>
#include <vector>


int main()
{
    std::cout << "The answer to the Ultimate Question of Life,\n"
              << "the Universe, and Everything is:"
              << std::endl << 6 * 7 << std::endl;
    //int o2 = 084; // error
    int o1 = 042;
    std::cout << o1 << std::endl;
    int h1 = 0x42;
    int h2 = 0xfa;
    std::cout << h1 << ',' << h2 << std::endl;
    int b1 = 0b11111010;
    std::cout << b1 << std::endl;
    long d = 5'546'687'616'861'129l;
    std::cout << d << std::endl;
    std::string s3 = "This a very long and clumsy text "
                "that is too long for one line.";

    std::cout << s3 << std::endl;

    int i1= 3.14; // compiles despite narrowing 
    //int i1n = {3.14};

    unsigned u2 = -3; // Compiles despite narrowing 
    //unsigned u2n = {-3};
    float f1 = {3.14};

    unsigned u3 = {3};
    int i2 = {2};

    unsigned u4 = {i2}; // warning: narrowing conversion 
    int i3 = {u3}; // warning: narrowing conversion 

    long l = 1234567890123;
    long l2 = l + 1.0f - 1.0; // imprecise
    long l3 = l + (1.0f - 1.0); // correct

    std::cout << l2 << std::endl;
    std::cout << l3 << std::endl;

    int b2 = 0b100;
    std::cout << (b2 >> 1) << std::endl;



    for (int i= 0, j= 0, p= 1; i < 10; ++i, j+= 4, p*= 2)
        std::cout << "i= " << i << " j= " << j << " p= " << p << std::endl;
    return 0;
}
