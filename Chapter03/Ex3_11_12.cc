#include <cmath>
#include <iostream>

using namespace std;

template <typename F, unsigned N>
class nth_derivative
{
    using prev_derivative= nth_derivative<F, N-1>;
public:
    nth_derivative(const F& f, double h) : h(h), fp(f, h) {}

    double operator()(double x) const {
        return (fp(x) - fp(x-h)) / h;
    }
private:
    double h;
    prev_derivative fp;
};

// Specialisation of `nth_derivative` class for N=1 (to stop inifinite recursion)
template <typename F>
class nth_derivative<F, 1>{
public:
    nth_derivative(const F& f, double h) : h(h), f(f){}

    double operator()(double x) const {
        return (f(x) - f(x-h)) / h;
    }
private:
    double h;
    F f;
};

// Functor
// 2*cos(x) + x^2
class cos_func {
public:
    cos_func(double a=2) : a(a) {}

    double operator()(double x) const{
        return (a * cos(x)) + (x*x);
    }
private:
    double a;
};

int main()
{
    double dd = nth_derivative<cos_func, 2>(cos_func(), 0.01)(1);
    cout << dd << endl;

    //lambda
    double a = 2;
    auto cos_lambda = [a](double x){ return (a*cos(x)) + (x*x); };
    double dd2 = nth_derivative<decltype(cos_lambda), 2>(cos_lambda, 0.01)(1);
    cout << dd2 << endl;

    return 0;
}
