#include <iostream>
#include <typeinfo> // to enable c++filt in script
#include <string>
#include <vector>
#include <memory>

#include "../my_info.hpp"

using namespace std;

template <typename T>
string l_or_r(const T&) { return "const"; }

template <typename T>
string l_or_r(T&) { return "mutable"; }

// Evil hack for testing
#define info(TPara, p) \
    cout << "Type of TPara is " << typeid(TPara).name() \
    << " == " << my_info<TPara>() \
    << ", is" << (is_lvalue_reference<TPara>::value ? "" : " no") << " lref" \
    << ", is" << (is_rvalue_reference<TPara>::value ? "" : " no") << " rref" \
    << ", is" << (is_const<TPara>::value ? "" : " not") << " const\n" \
    << "Type of p is " << typeid(p).name() \
    << " == " << my_info<decltype(p)>() \
    << ", is" << (is_lvalue_reference<decltype(p)>::value ? "" : " no") << " lref" \
    << ", is" << (is_rvalue_reference<decltype(p)>::value ? "" : " no") << " rref" \
    << ", is" << l_or_r(p) \
    << "\n=======================\n\n";

struct rubbish{};

struct dummy
{
    dummy& operator=(int i) {j= i; return *this;}
    int j = 8;
};

template <typename TPara>
void f1(TPara p)
{
    info(TPara, p);
}

template <typename TPara>
void f2(const TPara& p)
{
    info(TPara, p);
}

template <typename TPara>
void f3(TPara& p)
{
    info(TPara, p);
}

template <typename TPara>
void f4(TPara&& p)
{
    info(TPara, p);
}
    
template <typename TPara>
void f5(TPara&& p)
{
    f4(forward<TPara>(p));
}

int main()
{
    cout << "\n\n";

    int     i= 0;
    int&    j= i;
    const int& k= i;

    cout << "f1: \n";
    f1(3);
    f1(i);
    f1(j);
    f1(k);

    unique_ptr<int> up;
    //f1(up);      //Error: no copy ctor
    f1(move(up));   //OKay: move ctor

    cout << "\nf2: \n";
    f2(3);
    f2(i);
    f2(j);
    f2(k);
    f2(up);

    cout << "\nf3: \n";
    // f3(3);
    f3(i);
    f3(j);
    f3(k);
    f3(up);

    cout << "\nf4: \n";
    cout << "p is 3.\n";
    f4(3);
    cout << "p is i.\n";
    f4(i);
    cout << "p is move(i).\n";
    f4(move(i));
    cout << "p is j.\n";
    f4(j);
    cout << "p is k.\n";
    f4(k);
    cout << "p is up.\n";
    f4(up);
    cout << "p is move(up).\n";
    f4(move(up));

    cout << "\nf5: \n";
    cout << "p is 3.\n";
    f5(3);
    cout << "p is i.\n";
    f5(i);
    cout << "p is move(i).\n";
    f5(move(i));
    cout << "p is j.\n";
    f5(j);
    cout << "p is k.\n";
    f5(k);
    cout << "p is up.\n";
    f5(up);
    cout << "p is move(up).\n";
    f5(move(up));

    cout << "\nf4(dummy{}): \n";
    f4(dummy{});

    using int_ref= int&;
    cout << "The type of int& && is " << my_info<int_ref&&>() << endl;
}
