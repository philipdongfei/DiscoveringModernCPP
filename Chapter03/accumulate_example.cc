#include <iostream>
#include <limits>


template <typename T>
struct list_entry
{
    list_entry(const T& value) : value(value), next(0) {}

    T    value;
    list_entry<T>* next;
};


template <typename T>
struct list_iterator
{
    list_iterator(list_entry<T>* entry) : entry(entry) {}
    bool operator!=(const list_iterator<T>& that) const
    {
        return entry != that.entry;
    }
    list_iterator<T> operator++()
    {
        entry= entry->next;
        return *this;
    }
    list_iterator<T> operator++(int)
    {
        list_iterator<T> tmp(*this);
        entry = entry->next;
        return tmp;
    }
    T& operator*() { return entry->value; }
    T operator*() const { return entry-> value; }

  private:
    list_entry<T>* entry;
};

template <typename T>
struct list
{
    list() : first(0), last(nullptr) {}
    ~list() {
        while (first) {
            list_entry<T> *tmp = first->next;
            delete first;
            first = tmp;
        }
    }
    void append(const T& x) {
        last = (first ? last->next : first) = new list_entry<T>(x);
    }
    list_iterator<T> begin() { return list_iterator<T>(first); }
    list_iterator<T> end() { return list_iterator<T>(0); }

    list_entry<T> *first, *last;
};

template <typename T>
T sum(const list<T>& l)
{
    T sum = 0;
    for (list_entry<T>* entry=l.first; entry != nullptr; entry=entry->next)
        sum += entry->value;
    return sum;
}

template <typename T>
inline T accumulate_array(T* a, T* a_end)
{
    T sum(0);
    for (; a != a_end; ++a)
        sum += *a;
    return sum;
}

template <typename Iter, typename T>
inline T accumulate(Iter it, Iter end, T init)
{
    for (; it != end; ++it)
        init += *it;
    return init;
}


int main(int argc, char* argv[])
{
    list<float> l;
    l.append(2.0f);
    l.append(4.0f);
    l.append(7.0f);

    std::cout << sum(l) << '\n';

    int ai[] = {2, 4, 7};
    double ad[] = {2., 4.5, 7.};

    std::cout << "sum ai is " << accumulate_array(ai, &ai[3]) << '\n';
    std::cout << "sum ad is " << accumulate_array(ad, ad+3) << '\n';

    std::cout << "array sum " << accumulate(ai, ai+3, 0.0) << '\n';
    std::cout << "list sum " << accumulate(l.begin(), l.end(), 0) << '\n';

    list_iterator<float> iter = l.begin();
    list_iterator<float> tmp = iter++;
    std::cout << "post-increment " << *tmp << '\n';
    std::cout << *iter << '\n';
    tmp = ++iter;
    std::cout << "pre-increment " << *tmp << '\n';
    std::cout << *iter << '\n';
    

    return 0;
}
