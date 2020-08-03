#include <iostream>
#include <random>

using namespace std;


void random_numbers()
{
    static random_device rd;
    static default_random_engine re(rd());
    cout << "Random numbers: ";
    for (int i = 0; i < 4; i++)
        cout << re << (i < 3 ? ", " : "");
    cout << '\n';
}

int main()
{
    random_numbers();
    random_numbers();

    return 0;
}
