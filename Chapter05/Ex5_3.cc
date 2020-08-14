#include <iostream>

template <typename I>
I gcd(I a, I b){
    std::cout << '(' << a << ',' << b << ')' << std::endl;
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// meta-program
template <int A, int B>
struct gcd_meta {
    static const int A_mod_B = A % B;
    static const int value = gcd_meta<B, A_mod_B>::value;
};

template <int A>
struct gcd_meta<A, 0> {
    static const int value = A;
};

int main(int argc, char** argv){

    const int a = 8, b = 12;

    std::cout << gcd(a, b) << std::endl;

    constexpr int result = gcd_meta<a, b>::value;
    std::cout << result << std::endl;

    return 0;

    
}

