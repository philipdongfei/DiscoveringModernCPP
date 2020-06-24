#include <memory>
#include <iostream>


std::shared_ptr<double> f()
{
    std::shared_ptr<double> p1{new double};
    std::shared_ptr<double> p2{new double}, p3= p2;
    std::cout << "p3.use_count() = " << p3.use_count() << std::endl;
    return p3;    

}
std::shared_ptr<double> ff()
{
    std::shared_ptr<double> p3 = std::make_shared<double>();
    std::shared_ptr<double> p4 = std::make_shared<double>(), p5= p4;
    std::cout << "p5.use_count() = " << p5.use_count() << std::endl;
    return p5;    

}

int main()
{
    std::shared_ptr<double> p = f();
    std::cout << "p.use_count() = " << p.use_count() << std::endl;
    std::shared_ptr<double> pp = ff();
    std::cout << "pp.use_count() = " << pp.use_count() << std::endl;
    return 0;
}
