#include <iostream>
#include <cassert>


constexpr unsigned short middle(int a)
{
    static_assert(sizeof(int)==4, "unexpected int size");
    static_assert(sizeof(short)==2, "unexpected short size");

    return (a>>8)&0xFFFF;
}

int main()
{
    using namespace std;
    
    int x = 0xFF00FF00; // assume sizeof(int)==4
    short y = middle(x); // y = 0x00FF

    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "y = " << y << endl;

    return 0;
}
