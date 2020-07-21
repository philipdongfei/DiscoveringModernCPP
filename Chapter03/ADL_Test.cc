

namespace rocketscience {
    namespace mat {
        struct sparse_matrix {};
        struct dense_matrix {};
        struct uber_matrix {}; 

        template<typename Matrix>
        double one_norm(const Matrix& A) { return 1.0; }

        template<typename Scalar, typename Matrix>
            Matrix operator*(const Scalar& a, const Matrix& A) {
                Matrix B;
                return B;
            }
    }

    namespace vec {
        struct sparse_vector {};
        struct dense_vector {};
        struct uber_vector {}; 

        template <typename Vector>
        double one_norm(const Vector& x) { return 2.0; }

        template <typename Scalar, typename Vector>
            Vector operator*(const Scalar& a, const Vector& x) {
                Vector y;
                return y;
            }
        template <typename Matrix, typename Vector>
            Vector operator*(const Matrix& A, const Vector& x){
                Vector y;
                return y;
            }
    }
    //1 Error: not found by ADL
    /*
    using vec::uber_vector;

    template <typename Vector>
    double one_norm(const Vector& x) { return 2.0; }
    */
}

int main()
{
    rocketscience::vec::uber_vector x;
    double norm_x = one_norm(x); // 1 Error: not found by ADL

    rocketscience::mat::uber_matrix A;
    rocketscience::vec::uber_matrix x, y;
    y = A * x;      // which overload is selected?
}
