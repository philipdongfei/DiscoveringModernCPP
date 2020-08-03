#include <iostream>
#include <random>
#include <functional>

using namespace std;


void use_bind()
{
    auto normal = bind(normal_distribution<>{},
            default_random_engine(random_device{}()));
    for (int i= 0; i < 6; ++i)
        cout << normal() << endl;

}

void use_lambda()
{
    auto normal = [re= default_random_engine(random_device{}()),
                n= normal_distribution<>{}]() mutable
                { return n(re); };

    for (int i= 0; i < 6; ++i)
        cout << normal() << endl;
}

int main()
{
    default_random_engine re(random_device{}());
    normal_distribution<> normal;

    for (int i= 0; i < 6; ++i)
        cout << normal(re) << endl;

    cout << '\n';
    use_bind();
    cout << '\n';
    use_lambda();
    cout << '\n';

    return 0;
}
