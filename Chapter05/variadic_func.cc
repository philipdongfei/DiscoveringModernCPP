#include <iostream>


using namespace std;

// Forward declaration
template <typename ...P> struct sum_type;

template <typename T>
struct sum_type<T>
{
    using type= T;
};

template <typename T, typename ...P>
struct sum_type<T, P...>
{
    using type= decltype(T() + typename sum_type<P...>::type());
};

template <typename ...P>
using sum_type_t= typename sum_type<P...>::type;


template <typename T>
inline T sum(T t) { return t;}

template <typename T, typename ...P>
inline sum_type_t<T, P...> sum(T t, P ...p)
{
    return t + sum(p...);
}

// Common Type
template <typename T>
inline T minimum(const T& t) { return t; }

#if 0
template <typename T, typename ...P>
typename std::common_type<T, P...>::type
minimum(const T& t, const P& ...p)
{
    typedef typename std::common_type<T, P...>::type res_type;
    return std::min(res_type(t), res_type(minimum(p...)));
}
#else
template <typename T, typename ...P>
inline auto minimum(const T& t, const P& ...p)
{
    using res_type= std::common_type_t<T, P...>;
    return std::min(res_type(t), res_type(minimum(p...)));
}



#endif

int main(int argc, char* argv[])
{
    auto s = sum(-7, 3.7f, 9u, -2.6);
    cout << "s is " << s << " and its type is "
         << typeid(s).name() << '\n';

    auto s2 = sum(-7, 3.7f, 9u, -42.6);
    cout << "s2 is " << s2 << " and its type is "
         << typeid(s2).name() << '\n';

    auto v = minimum(-7, 3.7f, 9u, -2.6);
    cout << "minimum(): " << v << endl;

    return 0;
    
}
