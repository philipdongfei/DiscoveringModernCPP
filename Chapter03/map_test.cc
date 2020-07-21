#include <iostream>
#include <string>
#include <vector>



template<class K, class V>
class Map{   // a simple map class
public:
    V& operator[](const K& v); // return the value corresponding to the key v
    std::pair<K, V>* begin() {return &elem[0]; }
    std::pair<K, V>* end() { return &elem[0]+elem.size(); }
private:
    std::vector<std::pair<K, V>> elem;  // 
};

template<class K, class V>
V& Map<K,V>::operator[](const K& k)
{
    for (auto& x : elem)
        if (k == x.first)
            return x.second;

    elem.push_back({k, V{}}); // add pair at end
    return elem.back().second;  //return the (default) value of the new element
}

int main()
{
    ::Map<std::string,int> buf;

    // ctrl+D : cin is end
    for (std::string s; std::cin>>s;) ++buf[s];

    for (const auto& x : buf)
        std::cout << x.first << ": " << x.second << '\n';

}
