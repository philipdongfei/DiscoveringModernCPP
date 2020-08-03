#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <complex>
#include "../print_compiler.hpp"

using namespace std;

double add(double x, double y)
{
    return x+y;
}

inline double sub(double x, double y)
{
    return x - y;
}

struct mult {
    double operator()(double x, double y) const {return x * y;}
};

template <typename Value>
struct power{
    Value operator()(Value x, Value y) const { return pow(x, y); }
    
};

struct greater_t {
    template <typename Value>
    Value operator()(Value x, Value y) const { return x > y; }
}greater_than;

struct dummy
{
    operator double() { return 4.0; }
};

int main(int argc, char* argv[])
{
    print_compiler();

    using bin_fun= function<double(double, double)>;

    bin_fun f = &add;
    cout << "f(6,3) = " << f(6, 3) << endl;

    vector<bin_fun> functions;
    //functions.push_back(&add);
    functions.push_back(add);
    functions.push_back(sub);
    functions.push_back(mult{});
    functions.push_back(power<double>{});
    functions.push_back(greater_than);
    functions.push_back([](double x, double y){ return x / y; });

    for (auto& f : functions)
        cout << "f(6,3) = " << f(6, 3) << endl;

    dummy d;
    cout << "functions[5](d, d) = " << functions[5](d, d) << endl;

    return 0;
}
