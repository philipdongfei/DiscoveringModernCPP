#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>


void with_io_exceptions(std::ios& io)
{
    io.exceptions(std::ios_base::badbit | std::ios_base::failbit);
}

int main(int argc, char* argv[])
{

    std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    std::cout.exceptions(std::ios_base::badbit | std::ios_base::failbit);

    std::ifstream myfile;
    with_io_exceptions(myfile);
    myfile.open("MMmatrix.txt");
    std::string line;
    int lineNo = 0;
    while (std::getline(myfile, line))
    {
        std::istringstream linereader(line);

        char first;
        linereader >> first;
        if (first == '%')
            continue;
        std::cout << line << std::endl;
        int rows, columns, number;
        double felement;
        /***
         * read double value has some bug
        for (int n= 0; n < 3; ++n)
        {
            double val;
            linereader >> val;
            std::cout << val << '\t';
        }
        std::cout << '\n';
        */
        if (lineNo == 0)
        {
            linereader >> rows >> columns >> number;
            std::cout << rows << '\t' << columns << '\t' 
                << number << std::endl;
        }
        else 
        {
            unsigned x, y;
            long double z;
            linereader >> std::dec >> x >> std::dec >> y >> std::scientific >> z;
            std::cout.setf(std::ios_base::showpos);
            std::cout << x << '\t' << y << '\t' 
                << std::scientific << z << std::endl;
        }
        ++lineNo;
    }
    myfile.close();

    return 0;
}
