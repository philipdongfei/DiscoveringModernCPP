#include <iostream>
#include <cstddef>
#include "../print_compiler.hpp"

using namespace std;

constexpr size_t popcount(size_t x)
{//counts the number of 1-bits in binary data.(C++ 14)
    int count = 0;
    for (; x != 0; ++count)
    {
        x&= x - 1;

    }
    return count;
    // return x == 0 ? 0 : popcount(x & x-1) + 1; // C++11
}

int main(int argc, char* argv[])
{
    print_compiler();

    constexpr size_t bits= popcount(0x5555);
    static_assert(popcount(0x5555) == 8, "popcount(0x5555) != 8");
    cout << "bits = " << bits << endl;

    return 0;
}


