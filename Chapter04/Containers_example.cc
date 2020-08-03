#include <iostream>
#include <vector>


int main()
{
    using namespace std;

    std::vector<int> v = {3,4,7,9};
    for (int i= 0; i < v.size(); ++i)
        v[i]*= 2;
    for (const auto& x : v)
        cout << x << ' ';
    cout << endl;

    for (auto& x : v)
        x *= 2;

    v.push_back(1);
    for (const auto& x : v)
        cout << x << ' ';
    cout << endl;

    return 0;

}
