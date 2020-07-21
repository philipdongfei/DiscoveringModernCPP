#include <iostream>

using namespace std;

namespace c1 {
    namespace c2 {
        struct cc {};
        void f(const cc& o) { cout << "c1::c2::f\n"; }
        
    }// namespace c2
    void f(const c2::cc& o) { cout << "c1::f\n"; }
}// namespace c1

void f(c1::c2::cc& o) { cout << "f\n"; }

namespace f1 {
    void f(const c1::c2::cc& o) { cout << "f1::f\n"; }
    namespace f2 {
        void f(const c1::c2::cc& o){ cout << "f1::f2::f\n"; }
        using ::f;
        void g()
        {
            c1::c2::cc o;
            f(o);
        }
    } // namespace f2
} // namespace f1

int main()
{
    f1::f2::g();
}
