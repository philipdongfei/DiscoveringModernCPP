#include <iostream>
#include <stdexcept>
#include <type_traits>



void myprintf(const char*){}

template <typename T>
bool Is_C_style_string()
{
    return true;

}

template <typename T>
bool Is_string()
{
    return true;

}

template <typename T>
bool Is_integral()
{
    return true;
}

template <typename T>
bool Is_floating_point()
{
    return true;

}

template <typename T, typename... Args> 
// variadic template argument list: one or more arguments
void myprintf(const char* s, T value, Args... args) 
// function argument list: two or more arguments
{
    using namespace std;

    while (s && *s){
        if(*s == '%') { // a format specifier or %%
            switch (*++s){
                case '%': // not format specifier
                    break;
                case 's':
                    if (!Is_C_style_string<T>() && !Is_string<T>())
                        throw runtime_error("Bad myprintf() format");
                    break;
                case 'd':
                    if (!Is_integral<T>()) throw runtime_error("Bad myprintf() format");
                    break;
                case 'g':
                    if (!Is_floating_point<T>()) throw runtime_error("Bad myprintf() format");
                    break;

            }
            cout << value;  //use first non-format argument
            myprintf(++s, args...); // do a recursive call with the tail of the argument list
            return;
        }
        cout << *s++;
    }
    throw runtime_error("extra arguments provided to myprintf");
}

struct Point
{
    Point(): x{0}, y{0} {}
    Point(uint x, uint y) : x{x}, y{y} {}

  private:
    uint x, y;
};

int main()
{
    using namespace std;

    myprintf("The value of %s is %g\n", "x", 3.14);
    cout << '\n';
    
    string name = "target";
    myprintf("The value of %s is %P\n", name, uint{34});
    cout << '\n';

    myprintf("The value of %s is %g\n", 7);
    cout << '\n';

    return 0;
}
