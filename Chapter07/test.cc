#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> v = {3, 1, 4};
    std::cout << std::size(v) << '\n';

    int a[] = { -5, 10, 15 };
    std::cout << std::size(a) << '\n';

    // since C++20 the signed size (ssize) can avail
    /*
    auto i = std::ssize(v);
    for (--i; i != -1; --i){
        std::cout << v[i] << ' ';
    }
    std::cout << "\n" "i = " << i << '\n';
    */
}

