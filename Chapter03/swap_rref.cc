#include <iostream>
#include <vector>



template<class T>
void swap(T& a, T& b) // "perfect swap" (almost)
{
    T tmp{move(a)};  // move from a
    a = move(b);    // move from b
    b = move(tmp); //move from tmp
}

template<class T>
void swap(T&& a, T& b)
{
    T tmp{move(a)};
    b = move(tmp);
}
template<class T>
void swap(T& a, T&& b)
{
    T tmp{move(b)};
    a = move(tmp);
}

void f1(std::vector<int>& v)
{
    swap(v, std::vector<int>{1,2,3}); // swap(T&a, T&& b). replace v's elements with 1,2,3

}
void f2(std::vector<int>& v)
{
    swap(std::vector<int>{7,8,9}, v); // swap(T&& a, T&b) 
}

void f(std::string& s, std::vector<int>& v)
{
    s.shrink_to_fit(); // make s.capacity()==s.size()
    swap(s, std::string{s}); // make s.capacity()==s.size()

    v.clear();  // make v empty
    swap(v, std::vector<int>{}); // make v empty
    v = {};     // make v empty
}

int main()
{
    std::vector<int> v{4,5,6};
    for (auto e : v)
        std::cout << e << ' ';
    std::cout << '\n';
    f2(v);
    for (auto e : v)
        std::cout << e << ' ';
    std::cout << '\n';

    //
    std::string s{"abc"};
    f(s, v);
    std::cout << s << '\n';
    for (auto e : v)
        std::cout << e << ' ';
}
