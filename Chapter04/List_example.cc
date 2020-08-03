#include <list>
#include <iostream>
#include <algorithm>


int main()
{
    using namespace std;

    list<int> l = {3, 4, 7, 9};
    auto it = find(begin(l), end(l), 4), it2 = find(begin(l), end(l), 7);
    l.erase(it);
    cout << "it2 still points to " << *it2 << '\n';
    return 0;
}
