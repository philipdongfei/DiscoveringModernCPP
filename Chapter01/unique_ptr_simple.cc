#include <memory>
#include <iostream>



std::unique_ptr<int> f(std::unique_ptr<int> p)
{
    ++*p;
    return p;

}

void f2(const std::unique_ptr<int>& p)
{
    ++*p;
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) //default deleter version
{
    return std::unique_ptr<T>{new T{args...}};
}


void use()
{
    std::unique_ptr<int> p{new int{7}};
    //p = f(p);  // error: no copy constructor
    p = f(move(p));  // transfer ownership there and back
    std::cout << *p << std::endl;
    f2(p);   // pass a reference
    std::cout << *p << std::endl;
    std::unique_ptr<int> mp = make_unique<int>(10);
    std::cout << *mp << std::endl;
}

int main(void)
{
    use();

    return 0;
}
