#include <iostream>
#include <boost/core/demangle.hpp>

template <unsigned Order, typename Value>
class tensor {

};

template <typename Value>
using vector = tensor<1, Value>;

template <typename Value>
using matrix = tensor<2, Value>;

int main()
{

    std::cout << "type of vector<float> is "
              << boost::core::demangle(typeid(vector<float>).name()) << '\n';
    std::cout << "type of matrix<float> is "
              << boost::core::demangle(typeid(matrix<float>).name()) << '\n';

    return 0;
}
