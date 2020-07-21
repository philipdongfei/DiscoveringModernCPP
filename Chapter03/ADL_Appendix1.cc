#include <iostream>

using namespace std;

namespace c1 {
    namespace c2 {
        struct cc {};
        void f(cc& o) { cout << "c1::c2::f\n"; } //#1
        
    }// namespace c2
}// namespace c1

void f(c1::c2::cc& o) { cout << "f\n"; }

namespace f1 {
    void f(const c1::c2::cc& o) { cout << "f1::f\n"; } // #2
    namespace f2 {
        void g()
        {
            c1::c2::cc o;
            const c1::c2::cc c(o);
            f(o); // #1
            f(c); // #2
        }
        void f(c1::c2::cc& o){ cout << "f1::f2::f\n"; } //#3
    } // namespace f2
} // namespace f1

int main()
{
    f1::f2::g();
}
