#include <iostream>
#include <cmath>

using namespace std;

double sin_plus_cos(double x)
{
    return sin(x) + cos(x);
}

double fin_diff(double f(double), double x, double h)
{
    return ( f(x+h) - f(x) ) / h;
}

int main()
{
    cout << fin_diff(sin_plus_cos, 1., 0.001) << '\n';
    cout << fin_diff(sin_plus_cos, 0., 0.001) << '\n';

    return 0;
}
