#include <memory>


std::unique_ptr<double> f()
{
    return std::unique_ptr<double>{new double};
}

int main()
{
    std::unique_ptr<double> dp{new double};
    *dp = 7;

    double* raw_dp = dp.get();

    //std::unique_ptr<double dp2{dp}; // Error: no copy allowed
    //dp2 = dp;    // ditto

    std::unique_ptr<double> dp4{move(dp)}, dp5;
    dp5 = move(dp4);

    std::unique_ptr<double> dp3;
    dp3 = f();
    return 0;
}
