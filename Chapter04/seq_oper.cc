#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>
#include <complex>
#include <cmath>
#include "../print_compiler.hpp"

template <typename Seq>
void make_unique_sequence(Seq& seq)
{
    using std::begin; using std::end; using std::distance;

    std::sort(begin(seq), end(seq));
    auto it = std::unique(begin(seq), end(seq));
    seq.resize(distance(begin(seq), it));

}


int main()
{
    using namespace std;

    print_compiler();

    // copy
    vector<int> seq = {3,4,7,9,2,5,7,8}, v;
    v.resize(seq.size());
    copy(seq.begin(), seq.end(), v.begin());
    for (auto x : v)
        cout << x << ' ';
    cout << '\n';

    copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, ", "));

    //unique
    cout << '\n';
    vector<int> seq1 = {3,4,7,9,2,5,7,8,3,4,3,9};
    sort(seq1.begin(), seq1.end());
    auto it = unique(seq1.begin(), seq1.end());
    cout << "it = " << *it << endl;
    cout << "distance = " << distance(seq1.begin(), it) << endl;
    seq1.resize(distance(seq1.begin(), it));
    copy(seq1.begin(), seq1.end(), ostream_iterator<int>(cout, ", "));
    cout << '\n';

    // sort
    vector<int> seq2 = {3,4,7,9,2,5,7,8,3,4,3,9};
    sort(seq2.begin(), seq2.end(), [](int x, int y){return x > y;});
    copy(seq2.begin(), seq2.end(), ostream_iterator<int>(cout, ", "));
    cout << '\n';

    using cf = complex<float>;
    vector<cf> vv = {{3,4}, {7,9}, {2,5}, {7,8}};
    sort(vv.begin(), vv.end(), [](cf x, cf y){ return abs(x)<abs(y); }); // 
    for (auto x : vv)
        cout << "{" << real(x) <<',' << imag(x) << "},  ";
    cout << '\n';

    auto lex = [](cf x, cf y){ return real(x)<real(y)
                                || real(x)==real(y) && imag(x)<imag(y);};

    sort(vv.begin(), vv.end(), lex);
    for (auto x : vv)
        cout << "{" << real(x) <<',' << imag(x) << "},  ";
    cout << '\n';


    return 0;
}
