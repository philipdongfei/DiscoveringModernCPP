#include <set>
#include <iostream>

int main()
{
    using namespace std;

    set<int> s = {1,3,4,7,9};
    s.insert(5);
    for (int i = 0; i < 6; ++i)
        cout << i << " appears " << s.count(i) << " times.\n";
    cout << endl;

    cout << "ms count: " << '\n';
    multiset<int> ms = {1,3,4,7,9,1,1,4};
    ms.insert(4);
    for (int i = 0; i < 6; ++i)
        cout << i << " appears " << ms.count(i) << " time(s).\n";
    cout << endl;

    return 0;
}
