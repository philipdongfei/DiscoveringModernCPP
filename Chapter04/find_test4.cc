#include <iostream>
#include <list>
#include <algorithm>


bool check(int i) { return i > 4 && i < 7; }

int main()
{
    using namespace std;
    list<int> seq = {3,4,7,9,2,5,7,8};
    auto it = find_if(begin(seq), end(seq), check);
    cout << "The first value in reange is " << *it << '\n';

    it = find_if(begin(seq), end(seq),
            [](int i){ return i > 4 && i < 7; });
    cout << "The first value in reange is " << *it << '\n';

    return 0;
}


