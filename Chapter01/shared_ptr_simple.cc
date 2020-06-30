#include <memory>
#include <iostream>
#include <string>


struct S {
    int i;
    std::string s;
    double  d;
    S(int ii, std::string ss, double dd)
    {
        i = ii;
        s = ss;
        d = dd;
    }
};

int main()
{
    auto p = std::make_shared<S>(1,"Ankh Morpork", 4.65);

    std::cout << p->i << " " << p->s << " " << p->d << std::endl;

    return 0;
}
