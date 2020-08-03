#include <iostream>
#include <tuple>
#include <functional>
#include <typeinfo>
#include "../print_compiler.hpp"
#include "Tuple.hpp"


using namespace std;

template <typename T1, typename T2, typename T3, typename T4>
void print_elements(ostream& os, const Tuple<T1,T2,T3,T4>& t)
{
    os << t.x << ", ";
    print_elements(os, *t.base());
}


template <typename T1, typename T2, typename T3 >
void print_elements(ostream& os, const Tuple<T1,T2,T3>& t)
{
    os << t.x << ", ";
    print_elements(os, *t.base());
}

template <typename T1, typename T2 >
void print_elements(ostream& os, const Tuple<T1,T2>& t)
{
    os << t.x << ", ";
    print_elements(os, *t.base());
}

template <typename T1  >
void print_elements(ostream& os, const Tuple<T1>& t)
{
    os << t.x;
}

template<>
void print_elements(ostream& os, const Tuple<>& t)
{
    os << " ";
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<<(ostream& os, const Tuple<T1,T2,T3,T4>& t)
{
    os << "{";
    print_elements(os, t);
    os << "}";
    return os;
}

template <int N, typename T1, typename T2, typename T3, typename T4>
Select<N, T1, T2, T3, T4>& get(Tuple<T1,T2,T3,T4>& t)
{
    return getNth<Select<N, T1,T2,T3,T4>,N>::get(t);
}

template <int N, typename T1, typename T2, typename T3>
const Select<N, T1, T2, T3>& get(const Tuple<T1,T2,T3>& t)
{
    return getNth<Select<N,T1,T2,T3>,N>::get(t);
}


template <typename Ret, int N>
struct getNth {
    template<typename T>
    static Ret& get(T& t)
    {
        return getNth<Ret, N-1>::get(*t.base());
    }

    template <typename T>
    static const Ret& get(const T& t)
    {
        return getNth<Ret, N-1>::get(*t.base());
    }
};

template <typename Ret>
struct getNth<Ret, 0>{
    template <typename T>
    static Ret& get(T& t)
    {
        return t.x;
    }
    template <typename T> static const Ret& get(const T& t){
        return t.x;
    }
};

template <typename T>
constexpr auto operator[](T t, int N)
{
    return get<N>(t);
}

template <typename T1, typename T2, typename T3, typename T4>
Tuple<T1,T2,T3,T4> make_tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
{
    return Tuple<T1,T2,T3,T4>{t1,t2,t3,t4};
}





int main(int argc, char* argv[])
{
    tuple<string, int, double> t2("Sild", 123, 3.14);
    auto t = make_tuple(string("Herring"), 10, 1.23);

    /*
    string s = get<0>(t);
    cout << "t::s = " << s << '\n';
    int x = get<1>(t2);
    cout << "t2::x = " << x << '\n';
    double d = get<2>(t);
    cout << "t::d = " << d << '\n';
    */


    Tuple<double, int, char> x{1.1, 42, 'a'};
    cout << x << "\n";
    //cout << get<1>(x) << "\n";

    cout << Tuple<double,int,int,int>{1.2,3,5,7} << "\n";
    cout << Tuple<double,int,int>{1.2,3,5} << '\n';
    cout << Tuple<double,int>{1.2,3} << '\n';
    cout << Tuple<double>{1.2} << '\n';
    cout << Tuple<>{} << '\n';


    return 0;
}
