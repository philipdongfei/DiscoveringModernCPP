#include <initializer_list>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

class vector
{
public:
    vector(unsigned int size) : 
        my_size(size), data(new double[my_size]) {}

    vector() : my_size(0) {}

    vector(const vector& that)
        : my_size(that.my_size), data(new double[my_size])
    {
        for (int i=0; i<my_size; ++i)
            data[i] = that.data[i];
    }

    // move constructor
    vector(vector&& v)
        : my_size(v.my_size), data(v.data)
    {
        v.data = 0;
        v.my_size = 0;
    }


    // Initialize Lists
    vector(std::initializer_list<double> values)
        : my_size(values.size()), data(new double[my_size])
    {
        std::copy(std::begin(values), std::end(values),
                std::begin(data));
    }

    vector& operator=(std::initializer_list<double> values)
    {
        assert(my_size == values.size());
        std::copy(std::begin(values), std::end(values),
                std::begin(data));
        return *this;
    }

    void operator=(const vector& that)
    {
        assert(that.my_size == my_size);
        for (int i=0; i<my_size; ++i)
            data[i] = that.data[i];
    }

    vector& operator=(const vector& that)
    {
        if (this == &that)
            return *this;

        assert(that.my_size == my_size);
        for (int i=0; i<my_size; ++i)
            data[i] = that.data[i];
        return *this;
    }

    vector& operator=(vector&& src)
    {
        assert(my_size == 0 || my_size == src.my_size);
        std::swap(data, src.data);
        return *this;
    }

    int size() const { return my_size; }
    int size() { return my_size; }

    double& operator[](int i) const {
        assert(i>=0 && i<my_size);
        return data[i];
    }

    double& operator[](int i) {
        assert(i>=0 && i<my_size);
        return data[i];
    }

    vector operator+(const vector& that) const {
        assert(that.my_size == my_size);
        vector sum(my_size);
        for (int i=0; i<my_size; ++i)
            sum[i] = (*this)[i] + that[i];
        return sum;
    }
private:
    unsigned int     my_size;
    std::unique_ptr<double[]> data;
};
