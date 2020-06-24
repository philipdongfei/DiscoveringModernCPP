#include <iostream>

int main()
{
    int a = 5; // define a#1
    std::cout << "a=" << a << std::endl;
    {
        a = 3;  // assign a#1, a#2 is not defined yet
        std::cout << "a=" << a << std::endl;
        int a;  // define a#2
        a = 8;  // assign a#2, a#1 is hidden
        std::cout << "a=" << a << std::endl;
        {
            a = 7; // assign a#2
            std::cout << "a=" << a << std::endl;
        }
    }           // end of a#2's scope
    a = 11;     // assign to a#1 (a#2 out of scope)
    std::cout << "a=" << a << std::endl;

    return 0;
}
