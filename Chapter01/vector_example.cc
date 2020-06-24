#include <iostream>
#include <vector>
#include <cassert>

std::vector<float> add(const std::vector<float>& v1, const std::vector<float>& v2)
{
    assert(v1.size() == v2.size());
    std::vector<float> s(v1.size());
    for (unsigned i = 0; i < v1.size(); ++i)
        s[i] = v1[i] + v2[i];
    return s;
}

int main()
{
    std::vector<float> v= {1.0, 2.0, 3.0}, w= {7.0, 8.0, 9.0}, s= add(v, w);
    //for (unsigned i = 0; i < s.size(); ++i)
    for (float x : s)
        std::cout << x << std::endl;
    return 0;
}
