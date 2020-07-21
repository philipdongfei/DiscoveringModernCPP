#include <iostream>
#include <memory>

struct Record {
    Record() { a = 10; }
    Record(int x) { a = x; }
    ~Record() { a = 0; }
    int a;
};

void use(std::unique_ptr<Record> p, std::unique_ptr<int> q)
{
    if (!p) 
        throw Invalid_unique_ptr{};

    bool b = p; 
    int x = p+q;
}

int main()
{
    auto p = std::make_unique<Record>(3);
    std::unique_ptr<int> q = nullptr;
    *q = 1;

    use(p, q);
    
}
