#include <iostream>

using namespace std;

//decltype() 
template <class T, class U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) -> Matrix<decltype(T{}+U{})>
{
    Matrix<decltype(T{}+U{})> res;
    for (int i=0; i!=a.rows(); ++i)
        for (int j=0; j!=a.cols(); ++j)
            res(i,j) += a(i,j) + b(i,j);
    return res;
}

int main()
{
    auto v1{12345};
    auto v2{'c'};
    //auto v3{f()};

}
