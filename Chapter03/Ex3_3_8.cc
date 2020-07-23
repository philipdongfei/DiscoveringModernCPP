#include <memory>
#include <exception>
#include <iostream>

using namespace std;

class EmptyStack: public exception {
    virtual const char* what() const throw(){
        return "The stack is empty.";
    }
} emptystack;

class FullStack: public exception {
    virtual const char* what() const throw() {
        return "The stack is full.";
    }
} fullstack;

template <typename T>
class GenericStack {
    public:
        GenericStack(unsigned max_size=4096) : max_size(max_size), m_size(0) {
            m_stack = unique_ptr<T[]>(new T[max_size]);
        }

        T& top(){
            if (m_size == 0){
                throw emptystack;
            }
            return m_stack[m_size-1];
        }

        void pop(){
            if (m_size == 0){
                throw emptystack;
            }
            --m_size;
        }

        void push(T e){
            if (m_size == max_size){
                throw fullstack;
            }
            m_stack[m_size] = e;
            ++m_size;
        }
        void clear(){
            if (m_size == 0)
                throw emptystack;
            m_size = 0;
        }

        unsigned size(){
            return m_size;
        }

        bool full(){
            return m_size == max_size;
        }

        bool empty(){
            return m_size == 0;
        }

    private:
        unsigned max_size;
        unsigned m_size;
        unique_ptr<T[]> m_stack; // using a unique_pointer array instead of vector to make it harder
};

int main() {
    GenericStack<unsigned> integal_stack = GenericStack<unsigned>(10);

    for (unsigned i = 0; i < 10; ++i)
        integal_stack.push(i);

    cout << "top: " << integal_stack.top() << endl;
    cout << "size: " << integal_stack.size() << endl;
    integal_stack.pop();
    cout << "pop once. " << endl;
    cout << "top: " << integal_stack.top() << endl;
    cout << "size: " << integal_stack.size() << endl;
    integal_stack.pop();
    cout << "pop once. " << endl;
    cout << "top: " << integal_stack.top() << endl;
    cout << "size: " << integal_stack.size() << endl;
    integal_stack.push(10);
    cout << "push 10: " << endl;
    integal_stack.pop();
    cout << "pop once. " << endl;
    cout << "top: " << integal_stack.top() << endl;
    cout << "size: " << integal_stack.size() << endl;

    cout << "is full: " << integal_stack.full() << endl;
    cout << "is empty: " << integal_stack.empty() << endl;
    integal_stack.clear();
    cout << "is empty: " << integal_stack.empty() << endl;
    cout << "size: " << integal_stack.size() << endl;

    

    return 0;
}
