#include <iostream>

int main(void)
{
    double eps = 0.001;

    do {
        std::cout << "eps= " << eps <<  '\n';
        eps /= 2.0;
    } while (eps > 0.0001);

    return 0;
}
