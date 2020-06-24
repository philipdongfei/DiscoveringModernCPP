#include <iostream>
#include <valarray>

int main()
{
    std::valarray<float> v= {1.0, 2.0, 3.0}, w= {7.0, 8.0, 9.0}, s= v + 2.0f * w;
    v = sin(s);
    for (float x : v)
        std::cout << x << ' ';
    std::cout << '\n';

    return 0;
}
