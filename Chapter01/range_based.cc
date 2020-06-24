#include <iostream>

int main(void)
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    for (int i : primes)
        std::cout << i << " ";

    return 0;
}
