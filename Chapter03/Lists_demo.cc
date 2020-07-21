#include <iostream>
#include <initializer_list>
#include <limits>


struct S {int a, b;};
struct SS { double a, b; };

void f(S);

void g(S);
void g(SS);

void h()
{
    f({1,2});

    //g({1,2}); // error: ambiguous
    g(S{1,2});
    g(SS{1,2});
}

void f()
{
    std::initializer_list<int> lst{1,2,3};
    std::cout << *lst.begin() << '\n';
    //*lst.begin() = 2; //error
    std::cout << *lst.begin() << '\n';
}

int high_value(std::initializer_list<int> val)
{
    int high = std::numeric_limits<int>::lowest();
    if (val.size() == 0) return high;

    for (auto x : val)
        if (x > high)
            high = x;

    return high;

}

int main()
{
    using namespace std;
    h();
    f();

    int v1 = high_value({1,2,3,4,5,6,7});
    int v2 = high_value({-1,2,v1,4,-9,20,v1});
    cout << "v1 = " << v1 << '\n';
    cout << "v2 = " << v2 << '\n';

    
    return 0;
}

void f(S x) {
    std::cout << "f: " << x.a << ',' << x.b << '\n';

}

void g(S x) {
    std::cout << "g(S): " << x.a << ',' << x.b << '\n';
}

void g(SS x) {
    std::cout << "g(SS): " << x.a << ',' << x.b << '\n';
}
