#include <vector>

namespace math {

class my_vector {
public:
    typedef double value_type;

    my_vector( int n ){
        V = std::vector<double>(n);
    }
    // copy constructor from type itself
    my_vector(const my_vector& V_scr) : V(V_scr){}

    // constructor from generic vector
    template <typename Vector>
    my_vector( Vector& V_scr ) : V(V_scr.V) {};

    //Assignment operator
    my_vector& operator=( my_vector const& V_scr ){
        V = V_scr.V;
        return *this;
    }

    // Assignment for generic Vector
    template <typename Vector>
        my_vector& operator=( Vector const& v ){
            V = v;
            return *this;
    }

    //get operator
    value_type& operator()(int i) {
        return V[i];
    }

    int size() const {
        return V.size();
    }

    // get operator
    value_type operator() (int i) const {
        return V[i];
    }
private:
    std::vector<double> V;
    
};

template <typename Scalar, typename Vector>
class scalar_times_vector_expressions
{};

template <typename Scalar, typename Vector>
scalar_times_vector_expressions<Scalar, Vector>
operator*(Scalar const& s, Vector const& v)
{
    return scalar_times_vector_expressions<Scalar, Vector>(s, v);
}
}

int main(){
    math::my_vector v(5);
    math::my_vector w(5);
    w = 5.0 * v;

    w = 5.0 * (7.0 * v);
    //w = v + 7.0 * v; 
    
    return 0;

}
