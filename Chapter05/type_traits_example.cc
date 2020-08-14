#include <iostream>
#include <typeinfo>

using namespace std;


class X{

public:
    void inside();

private:
    X& operator=(const X&);

};

void X::inside()
{
    cout << "inside=: " << is_copy_assignable<X>::value << '\n';
    cout << "inside~: " << is_destructible<X>::value << '\n';
}

void outside()
{
    cout << "outside =: " << is_copy_assignable<X>::value << '\n';
    cout << "outside ~: " << is_destructible<X>::value << '\n';
}

template <typename ...T>
struct common_type;

template <typename T>
struct common_type<T> {
    using type = T;
};

template <typename T, typename U>
struct common_type<T, U>{
    using type= decltype(true ? declval<T>() : declval<U>());
};

template <typename T, typename U, typename... V>
struct common_type<T, U, V...>{
    using type = typename common_type<typename common_type<T, U>::type, V...>::type;
};


int main()
{
    X x;
    x.inside();
    outside();

    template <typename T, typename U>
    using Common_type= typename common_type<T,U>::type;

    Common_type<int, double> x1;
    //Common_type<int, string> x;
    Common_type<int, short, long, long long> x3;
    Common_type<Shape*, Circle*> x4;
    Common_type<void*, double*, Shape*> x5;   


    return 0;
}
