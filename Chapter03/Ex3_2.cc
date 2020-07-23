#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
string to_string(const T& s){
    stringstream ss;
    string tostr{""};
    ss << s;
    ss >> tostr;
    return tostr;
}

template <typename T>
string _to_tuple_string(T a){
    return to_string(a);
}

template <typename T, typename ...P>
string _to_tuple_string(T a, P ...p){
    string str = to_string(a) + ", " + _to_tuple_string(p...);
    return str;
}

template <typename T, typename ...P>
string to_tuple_string(T a, P ...p){
    string str = "(" + _to_tuple_string(a, p...) + ")";
    return str;
}

int main(){
    string s = to_tuple_string(false, 1, "2", 3.1415, "big");
    cout << s << endl;

    return 0;
}


