#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>


bool less_func(double x, double y){
    return abs(x) < abs(y);
}


int main(){
    using namespace std;
    vector<double> seq = {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4,8.2};
    auto less = [](double x, double y) { return abs(x) < abs(y); };
    sort (begin(seq), end(seq), less);
    sort (begin(seq), end(seq), less_func);
    
    copy(seq.begin(), seq.end(), ostream_iterator<double>(cout, ", "));
    /*
    for (auto v : seq){
        cout << v << ", ";
    }
    */
    cout << endl;

    return 0;
}
