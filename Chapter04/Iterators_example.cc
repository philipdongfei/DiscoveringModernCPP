#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

int main()
{
    using namespace std;

    list<int> l = {3,5,9,7};
    for (auto it = begin(l), e= end(l); it != e; ++it){
        int i = *it;
        ++(*it); 
        cout << i << ' ';
    }
    cout << endl;

    for (auto it = cbegin(l); it != cend(l); ++it){ //C++ 14
        int i = *it;
        cout << i << ' ';

    }
    cout << endl;

    for (auto i : l)
    {
        cout << i << ' ';
        ++i; 
    }
    cout << endl;

    for (auto& i : l)
    {

        cout << i << ' ' ;
        ++i;
    }
    cout << endl;

    for (const auto& i : l)
    {
        cout << i << ' ';
    //    ++i; //const

    }
    cout << endl;

    for (auto i : l)
    {
        cout << i << ' ';
    }
    cout << endl;
    
    auto it1 = begin(l);
    advance(it1, 1);
    auto it2 = begin(l);
    cout << "it move " << distance(it1, it2) << ": " << *it1 << endl;

    return 0;
}
