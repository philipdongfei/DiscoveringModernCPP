#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <functional>


using namespace std;

template<class C>
void print_modulo(const C& v, std::ostream& os, int m)
    // output v[i] to os if v[i]%m==0
{
    auto Modulo_print = [&os,m](int x){if(x%m==0) os<<x<<'\n';};
    for_each(begin(v), end(v),Modulo_print);
    //breadth_first(begin(v), end(v),Modulo_print);

}

template<typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::pair<U,V>& p)
{
    return os<<'{'<<p.first<<','<<p.second<<'}';
}

void print_all(const std::map<std::string,int>& m, 
        const std::string& label)
{
    std::cout<<label<<":\n{\n";
    for_each(m.begin(),m.end(),
            [](const std::pair<std::string,int>& p){std::cout<<p<<'\n';});
    std::cout<<"}\n";
}


class Request {
    //lambda and this
    //
    function<map<string,string>(const map<string,string>&)> oper; // operation
    map<string,string> values;   // arguments
    map<string,string> results;  // targets

public:
    Request(const string& s);    // parse and store request

    void execute()
    {
        [this](){ results=oper(values);}; // do oper to values yielding results
    }

};

void algo(std::vector<int>& v)
{
    int count = v.size();
    std::generate(v.begin(), v.end(),
            [count]()mutable{ return --count; });
}

void f(double y)
{
    cout << y << endl;
}

void g(double y)
{
// call and return
    [&]{f(y);};      // return type is void

    auto z1 = [=](double x){ return x+y; }; // return type is double
    cout << "z1: " << z1(6.0) << endl;
    //auto z2 = [=]{ if (y) return 1; else return 2; }  // error: body too complicated for return type deduction

    auto z3 = [y](){ return y+1.2; };    // return type is int
    cout << "z3: " << z3() << endl;
    auto z4 = [=,y]()->int { if(y) return 1; else return 2; }; // OK:explicit return type

    cout << "z4: " << z4() << endl;

}

template<class Target, class Source>
Target narrow_cast(Source v)
{
    auto r = static_cast<Target>(v);  // convert the value to the target type
    if (static_cast<Source>(r) != v)
        throw runtime_error("narrow_cast<>() failed");
    return r;
}

void test_narrow(double d, int i, char* p)
{
    auto c1 = narrow_cast<char>(64);
    //auto c2 = narrow_cast<char>(-64);  // will throw if chars are unsigned
    //auto c3 = narrow_cast<char>(264);  // will throw if chars are 8-bit and signed

    cout << "c1 = " << c1 << endl;
    //cout << "c2 = " << c2 << endl;
    //cout << "c3 = " << c3 << endl;

    auto d1 = narrow_cast<double>(1/3.0F);  //
    //auto f1 = narrow_cast<float>(1/3.0); // will probably throw

    cout << "d1 = " << d1 << endl;
    //cout << "f1 = " << f1 << endl;

    auto c4 = narrow_cast<char>(i); // may throw
    auto f2 = narrow_cast<float>(d);  //may throw

    cout << "c4 = " << c4 << endl;
    cout << "f2 = " << f2 << endl;

    //auto p1 = narrow_cast<char*>(i); //compile-time error
    //auto i1 = narrow_cast<int>(p);   // compile-time error

    auto d2 = narrow_cast<double>(i);  //may throw (but probably will not)
    auto i2 = narrow_cast<int>(d);    // may throw

    cout << "d2 = " << d2 << endl;
    cout << "i2 = " << i2 << endl;
}



int main()
{
//    using namespace std;
    vector<int> v{1,2,3,4,5,6,7,8,9};
    //ostream os(cout);
    cout << "algo: " << '\n'; 
    vector<int> v1(10);
    algo(v1);
    for (auto iv : v) {
        cout << iv << " ";
    }
    cout << '\n';
    cout << "print_modulo: " << '\n';
    print_modulo(v, cout, 3);
    cout << '\n';

    std::map<string, int> first;

    first["aa"]=10;
    first["bb"]=30;
    first["cc"]=60;
    first["dd"]=70;
    string label{"label"};

    print_all(first, label);

    double y{5.5};
    g(y);

    cout << "test narrow cast: " << '\n';

    char p = 'a';
    test_narrow(3.1415926, 8, &p); 

    // name cast
    char x = 'a';
    //int* p1 = &x;                   //error
    //int* p2 = static_cast<int*>(&x); // error
    int* p3 = reinterpret_cast<int*>(&x); // ok
    
    struct B {};
    struct D : B {};

    B* pb = new D;
    //D* pd = pb;   //error
    D* pd = static_cast<D*>(pb); // ok


    return 0;
}
