#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "../print_compiler.hpp"

int main()
{
    using namespace std;

    print_compiler();

    vector<float> v= {3.1, 4.2, 7, 9.3, 2, 5, 7, 8, 3, 4},
        w(10), x(10), y(10);
    iota(w.begin(), w.end(), 12.1);
    cout << "iota: \n";
    copy(w.begin(), w.end(), ostream_iterator<float>(cout, ", "));
    cout << '\n';

    partial_sum(v.begin(), v.end(), x.begin());
    cout << "partial_sum: \n";
    copy(x.begin(), x.end(), ostream_iterator<float>(cout, ", "));
    cout << '\n';

    adjacent_difference(v.begin(), v.end(), y.begin());
    cout << "adjacent_difference: \n" ;
    copy(y.begin(), y.end(), ostream_iterator<float>(cout, ", "));
    cout << '\n';

    float alpha = inner_product(w.begin(), w.end(), v.begin(), 0.0f);
    cout << "alpha = " << alpha << endl;
    alpha = dot(v, w);
    cout << "alpha = " << alpha << endl;

    float sum_w = accumulate(w.begin(), w.end(), 0.0f);
    cout << "sum_w = " << sum_w << endl;
    float product_w = accumulate(w.begin(), w.end(), 1.0f,
            [](float x, float y) { return x*y; });
    cout << "product_w = " << product_w << endl;

    return 0;
}
