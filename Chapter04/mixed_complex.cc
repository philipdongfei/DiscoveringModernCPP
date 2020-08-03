#include <iostream>
#include <complex>

using namespace std;


template <typename T>
inline T twice(const T& z)
{
    return T{2} * z;

}

int main()
{

    complex<double> z(3, 5), c;
    c = twice(z);

    cout << c << endl;

    return 0;
}
