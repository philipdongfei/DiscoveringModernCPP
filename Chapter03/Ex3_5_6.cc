#include <iostream>
#include <stdexcept>

using namespace std;

class OddIterator {
public:
    OddIterator(int start = 1): i(start) {
        if (!check_odd_number(start)){
            throw domain_error("Start number `start` should be an odd number");
        }
    }

    OddIterator(OddIterator const &src): i(src.i){}

    bool check_odd_number(int num){
        return ((num+1)%2) == 0;
    }

    void increment(){
        i += 2;
    }

    //pre-increment
    OddIterator& operator++(){
        increment();
        return *this;
    }

    //post-increment
    OddIterator operator++(int){
        OddIterator tmp(*this);
        operator++();
        return tmp;
    }

    // Dereference operator
    int& operator* () {
        return i;
    }

    //Equality 
    bool operator==(OddIterator e2){
        return i == e2.i;
    }

    bool operator!=(OddIterator e2){
        return i != e2.i;
    }

    OddIterator(OddIterator&& src) : i(src.i) {}

    OddIterator& operator=(const OddIterator& src){
        i = src.i;
        return *this;
    }

    OddIterator& operator=(OddIterator&& src){
        i = src.i;
        return *this;
    }
    ~OddIterator(){}

protected:
    int i;

};

class OddRange {
public:
    OddRange(int start = 1, int end = 1): start_i(start), end_i(end){

    }
    
    OddIterator begin(){
        static OddIterator oi = OddIterator(start_i-2);
        return oi;
    }

    OddIterator end(){
        static OddIterator oi = OddIterator(end_i-2);
        return oi;
    }
private:
    int start_i;
    int end_i;
};

int main(){
    cout << *(++OddIterator(5)) << endl;

    cout << "OddRange: " << endl;
    for (int i : OddRange(7, 27)){
        cout << i << endl;
    }

    cout << endl;

    return 0;
}
