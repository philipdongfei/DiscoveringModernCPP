#include <iostream>
#include <cmath>



using namespace std;

struct functor_base
{
    virtual double operator() (double x) const= 0;
};

double finite_difference(functor_base const& f,
                        double x, double h)
{
    return (f(x+h) - f(x)) / h;
}

class para_sin_plus_cos
    : public functor_base
{
    public:
        para_sin_plus_cos(double p) : alpha(p) {}
        virtual double operator()(double x) const override
        {
            return sin(alpha * x) + cos(x);
        }
    private:
        double alpha;
};

int main()
{
    para_sin_plus_cos sin_1(1.0);
    cout << finite_difference(sin_1, 1., 0.001) << endl;

    double df1 = finite_difference(para_sin_plus_cos(2.), 1., 0.001),
           df0 = finite_difference(para_sin_plus_cos(2.), 0., 0.001);

    cout << "df1= " << df1 << endl;
    cout << "df0= " << df0 << endl;

    return 0;
}
