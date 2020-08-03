#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "../print_compiler.hpp"

struct no_seven{};
struct one_seven{};

int main(int argc, char* argv[])
{
    using namespace std;

    print_compiler();
    //vector<int> seq = {3,4,7,9,2,5,7,8};
    vector<int> seq = {3,4,9,2,5,8};
    auto it = find(seq.begin(), seq.end(), 7), it2 = it; // first 7

    if (it == seq.end())
        throw no_seven{};
    ++it2;
    auto end = find(it2, seq.end(), 7); // second 7
    if (end == seq.end())
        throw one_seven{};
    ++end;
    for (; it != end; ++it)
        cout << *it << ' ';
    cout << '\n';

    return 0;
}
