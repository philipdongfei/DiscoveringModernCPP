#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <initializer_list>
#include <cassert>


class polynomial {
public:

    polynomial(unsigned degree = 0) : m_degree(degree), m_coefficient(std::vector<double>(m_degree+1)) {}

    polynomial(const std::vector<double> coefficient): m_degree(coefficient.size()-1), m_coefficient(coefficient) {}

    polynomial(std::initializer_list<double> il):m_degree(il.size()-1){
        m_coefficient.assign(il.begin(), il.end());
    }
    polynomial(double c1, double c2, double c3):m_degree(3){
        
        m_coefficient.push_back(c1);
        m_coefficient.push_back(c2);
        m_coefficient.push_back(c3);
    }
    ~polynomial() {
        m_degree = 0;
        m_coefficient.clear();
    } 

    void set_coefficient(const std::vector<double>& coefficient){
        assert(m_degree == (coefficient.size() -1));
        m_coefficient = coefficient;
    }

    void set(const unsigned& i, const double& val){
        m_coefficient[i] = val;
    }
    void set_degree(const unsigned& i){
        m_degree = i;
    }
    
    friend inline bool empty(const polynomial& p) { 
        return p.m_coefficient.empty(); 
    } 
    friend inline unsigned size(const polynomial& p) { 
        return p.m_coefficient.size(); 
    }
    friend inline unsigned degree(const polynomial& p) { 
        return p.m_degree; 
    }
    friend inline double at(const polynomial& p, unsigned i) { 
        return p.m_coefficient[i]; 
    }

    friend inline std::vector<double> coefficient(const polynomial& p) { return p.m_coefficient; } 

    friend std::string const output_func(const polynomial& p) {
        std::stringstream output;
        for (double e : p.m_coefficient){
            if (e > 0)
                output << '+' << e << 'x' << '^' << 'n';  
        }
        output << std::endl;
        return output.str();
    } 

    // Ex2.8.2
    friend inline void move_poly(polynomial& p1, polynomial& p2){
        p1.m_degree = p2.m_degree;
        p1.m_coefficient = std::move(p2.m_coefficient);

    }
    polynomial(const polynomial& p) : m_degree(degree(p)) {
        m_coefficient = coefficient(p); 
    }
    polynomial(polynomial&& p) noexcept : m_degree(degree(p)){
        move_poly(*this, p);

    }
    polynomial& operator=(polynomial& p){
        m_coefficient = coefficient(p);
        m_degree = degree(p);
        return *this;
    }
    polynomial& operator=(polynomial&& p){
        move_poly(*this, p);
        p.set_degree(0);
        return *this;
    }

private:
    double m_degree{0.0};
    std::vector<double> m_coefficient{};
};


inline polynomial operator+(const polynomial& rp1, const polynomial& rp2)
{
    auto degree_new = std::max(degree(rp1), degree(rp2));
    polynomial lp = polynomial(degree_new);
    for (int i=0; i < degree_new; ++i){
        double c_i = 0;
        if (( i < degree(rp1) ) and (i < degree(rp2))){
            c_i = at(rp1, i) + at(rp2,i); 
        } else if ((i > degree(rp1)) && (i < degree(rp2))){
            c_i = at(rp2, i);
        } else if ((i < degree(rp1)) and (i >= degree(rp2))){
            c_i = at(rp1, i);
        } else {
            throw std::exception();
        }
        lp.set(i, c_i);
    }
    
    return lp;

}

std::ostream& operator<<(std::ostream& os, polynomial p)
{
    if (!empty(p)){
        os << output_func(p);
    }

    return os;
}

void initialize_list(){
    polynomial p{4,3,2,1};
    std::cout << p << std::endl;
}
polynomial polynomial_degree_2(double c0, double c1, double c2){
    polynomial p{c0, c1, c2};
    return p;
}
polynomial polynomial_from_old(polynomial p) {
    return p;
}

void copy_and_move_semantics(){
    polynomial p1;
    polynomial p2;
    p1 = p2;
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    polynomial p3{1,2,3};
    polynomial p4(p3);
    std::cout << "p3: " << p3 << std::endl;
    std::cout << "p4: " << p4 << std::endl;

    polynomial p5;
    p5 = polynomial_degree_2(0,1,2);
    std::cout << "p5: " << p5 << std::endl;

    polynomial p6;
    polynomial p7;
    p7 = polynomial_from_old(p6);
    std::cout << "p6: " << p6 << std::endl;
    std::cout << "p7: " << p7 << std::endl;
}

int main() {
    polynomial a{1,2,3};
    polynomial b{4,5,6};

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << a+b  << std::endl;

    copy_and_move_semantics();
}
