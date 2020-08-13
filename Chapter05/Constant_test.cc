#include <iostream>
#include <cmath>

template <long N>
struct static_long
{
    static const long value = N;
};

int main(int argc, char* argv[])
{
    using namespace std;

    const long i= 7, j= 8;
    static_long<i> si;
    cout << si.value << endl;

    const long k= i + j;
    static_long<k> sk;
    cout << sk.value << endl;

    /*
    long ll;
    cin >> ll;

    const long cl = ll;
    //static_long<cl> scl; //error
    */

    const long ri = floor(sqrt(i));
    static_long<ri> sri;

    cout << sri.value << endl;
    

    return 0;
}
