#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
string to_string (const T& s) {
    stringstream ss;
    string tostr{""};

    ss << s;
    ss >> tostr;
    return tostr;
}


int main() {
    cout << to_string(100) << endl;
    cout << to_string(3.1415) << endl;
    cout << to_string("300") << endl;

    return 0;
}
