#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

struct lambda_f
{
    lambda_f(double phi, double xi) : phi(phi), xi(xi) {}
    double operator()(double x) const
    {
        return sin(phi * x) + cos(x) * xi;
    }
    const double phi, xi;
};

template <typename F, typename T>
T inline fin_diff(F f, const T& x, const T& h)
{
    return (f(x+h) - f(x)) / h;
}

/*
// FIX 
struct lambda_ref_type
double operator()(double x) const
{
    lambda_ref_type(double& phi, double& xi) : phi(phi), xi(xi) {}
    double operator()(double x)
    {
        return sin(phi * x) + cos(x) * xi;
    }
    double& phi;
    double& xi;
};
*/

template <typename Matrix>
typename Matrix::value_type
frobenius_norm(const Matrix& A)
{
    using std::abs; using std::sqrt;
    using value_type = typename Matrix::value_type;
    value_type ss = 0;
    on_each_nonzero(A, [&ss](value_type x) { ss+=abs(x) * abs(x); });
    return sqrt(ss);
}

template <typename C>
void reverse_sort(C& c)
{
    sort(begin(c), end(c), [](auto x, auto y) { return x > y; });
}

/*
constexpr int sum() { return 0; }

template <class T, class... P>
constexpr T sum(T t, P... p)
{
    return t + sum(p...);  // recursion, return type is T
}
*/

template <typename T>
inline T sum(T t) { return t; }

template <typename T, typename ...P>
inline T sum(T t, P ...p)
{
    return t + sum(p...);
}

int main()
{

    double phi = 2.5, xi = 0.2;
    auto px = [phi,xi](double x){ return sin(phi * x) + cos(x) * xi; };
    phi = 3.5; xi = 1.2;
    auto a = fin_diff(px, 1., 0.001);

    cout << "a = " << a << endl;

    //auto l_inc = [phi](double x) {phi+= 0.6; return phi;};//Error
    auto l_mut = [phi](double x) mutable {phi+= 0.6; return phi;};//Error

    cout << "l_mut = " << l_mut(phi) << endl;


    int x = 4;
    auto y = 
        [&r= x, x= x + 1]()
        {
            r+= 2;    // increment r, a reference to outer x
            return x + 2; // return x + 2 where x is the outer x + 1
        }();
    cout << "y = " << y << endl;

    vector<int> v {10,20, 5, 15, 30,0};
    reverse_sort(v);
    for (int x : v)
        cout << x << ' ';
    cout << '\n';

    auto s = sum(-7, 3.7f, 9u, -2.6);
    cout << "s is " << s
         << " and its type is " << typeid(s).name() << '\n';

    auto s2 = sum(-7, 3.7f, 9u, -42.6);
    cout << "s2 is " << s2
         << " and its type is " << typeid(s2).name() << '\n';

    return 0;

}
