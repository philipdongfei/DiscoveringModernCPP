#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

template <typename T>
inline void test(const T& x)
{
    cout << "x = " << x << " ( " ;
    int oldp = cout.precision(numeric_limits<T>::digits10 + 1);
    cout << x << " )" << endl;
    cout.precision(oldp);
}

template <typename Container>
typename Container::value_type
inline minimum(const Container& c)
{
    using vt = typename Container::value_type;
    vt min_value = numeric_limits<vt>::max();
    for (const vt& x : c)
        if (x < min_value)
            min_value = x;
    return min_value;
}

template <typename T>
T square_root(const T& x)
{
    const T my_eps = T{2} * x * numeric_limits<T>::epsilon();
    T r = x;

    while (std::abs((r * r) - x) > my_eps)
        r= (r + x/r) / T{2};
    return r;
}


int main()
{
    test(1.f/3.f);
    test(1./3.0);
    test(1./3.0l);

    cout << square_root(1.f/3.f) << endl;
    cout << square_root(1./3.0) << endl;
    cout << square_root(1./3.0l) << endl;
    return 0;
}
