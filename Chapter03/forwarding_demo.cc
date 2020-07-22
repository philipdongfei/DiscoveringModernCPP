#include <iostream>

using namespace std;

template <typename F, typename... T>
void call(F&& f, T&&... t)
{
    f(forward<T>(t)...);
}

void g0()
{
    cout << "g0()\n";
}

template <typename T>
void g1(const T& t)
{
    cout << "g1(): " << t << '\n';
}

void g1d(double t)
{
    cout << "g1d(): " << t << '\n';
}

template <typename T, typename T2>
void g2(const T& t, T2&& t2)
{
    cout << "g2(): " << t << ' ' << t2 << '\n';
}

void test()
{
    call(g0);
    //call(g1); // error: too few argeuments
    call(g1<int>, 1);
    call(g1<double>, 1.2);
    call(g1d, 1.2);
    //call(g1d, "No way!"); // error: wrong argument type for g1d()
    //call(g1d, 1.2, "I can't count");   // error: too many arguments for g1d()
    call(g2<double, string>,1,"world!");

    int i = 99;   // testing with lvalues
    const char* p = "Trying";
    call(g2<double, string>, i, p);

    call([](){cout<<"I1()\n";});
    call([](int i){cout<<"I0():"<<i<<"\n";}, 17);
    call([i](){cout<<"I1():"<<i<<"\n";});

}

int main()
{
    test();

    return 0;
}
