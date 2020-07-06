#include <iostream>

class complex
{
    public:
        /*
        complex(double rnew, double inew)
        {
            r = rnew; i = inew;
        }
        complex(double r, double i): r(r), i(i) {}
        complex(double r): r(r), i(0) {}
        complex(): r(0), i(0) {}
        */
        complex(const complex& c) : i(c.i), r(c.r) {}
        //explicit complex(double rn = 0.0, double in = 0.0):r(rn),i(in){}
        //complex(double r = 0, double i = 0): r(r), i(i) {}
        complex(double r = 0.0, double i = 0.0) : r{r}, i{i} {}
        //complex(double r) : complex{r, 0.0} {}
        //complex() : complex{0.0} {}
        complex& operator=(const complex& src)
        {
            r = src.r; i = src.i;
            return *this;
        }
        complex& operator=(double nr)
        {
            r = nr; i = 0;
            return *this;
        }
        /*
        complex operator+(const complex& c2) const
        {
            return complex(r + c2.r, i + c2.i);
        }
        */
        /*
        ~complex()
        {
            std::cout << "So long and thanks for the fish.\n";
        }
        */

        /*
        double get_r() { return r;  } // causes clumsy
        void set_r(double newr) { r = newr;  } // code
        double get_i() { return i; }
        void set_i(double newi) { i = newi; }
        */
        complex operator+(double d) const;

        friend inline double const& real(const complex& c) {return c.r;}
        friend inline double& real(complex& c){ return c.r; }

        friend inline double const& imag(const complex& c) {return c.i;}
        friend inline double& imag(complex& c){ return c.i; }

        friend double& dings(complex& c);
        
        friend complex operator-(const complex& c1, const complex& c2)
        {
            return {c1.r - c2.r, c1.i - c2.i};
        }

    private: 
        double r = 0.0, i = 0.0; // C++11: default values of members

};


std::ostream& operator<<(std::ostream& os, complex c)
{
    os << '(' << real(c) << ',' << imag(c) << ')';
    return os;
}

inline complex operator+(const complex& c1, const complex& c2)
{
    std::cout << " -- c+c -- ";
    return complex(real(c1) + real(c2), imag(c1) + imag(c2));
}

inline complex operator+(double d, const complex& c2)
{
    std::cout << " -- d+c -- ";
    return complex(d + real(c2), imag(c2));
}

inline complex
complex::operator+(double d) const
{
    std::cout << " -- c+d -- ";
    return complex(r + d, i);
}

complex operator-(const complex& c1)
{ 
    std::cout << "free unary -\n";
    return complex(-real(c1), -imag(c1));
}


