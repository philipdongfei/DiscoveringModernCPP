#include <iostream>
#include <string>

using namespace std;

class person
{
public:
    person() {} // not implicity generated
    explicit person(const string& name) : name(name) {}

    void set_name(const string& n) { name= n; }
    string get_name() const { return name; }
    virtual void all_info() const { cout << "[person]  My name is " << name << endl; }

private:
    string name;
};

class student
    : public person
{
public:
    student(const string& name, const string& passed)
        : person(name), passed(passed){}
    virtual void all_info() const {
        cout << "[student] My name is " << get_name() << endl;
        cout << "   I passed the following grades: " << passed << endl;
    }
private:
    string passed;
};

void spy_on(const person& p)
{
    p.all_info();
}

void glueless(person p)
{
    p.all_info();
}


int main()
{
    person mark("Mark Markson");
    mark.all_info();

    cout << '\n';

    student tom("Tom Tomson", "Algebra, Analysis");
    tom.all_info();
    cout << '\n';

    person p(tom);
    person& pr= tom; // or pr(tom)
    person* pp= &tom; // or pp(&tom)

    p.all_info();
    cout << '\n';
    pr.all_info();
    cout << '\n';
    pp->all_info();
    cout << '\n';

    glueless(tom);
    cout << '\n';
    spy_on(tom);
    cout << '\n';
    
    return 0;
}

