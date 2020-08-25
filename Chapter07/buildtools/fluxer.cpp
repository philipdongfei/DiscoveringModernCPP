#include <iostream>

#include "solver.hpp"
#include "mesher.hpp"

int main(int argc, char* argv[])
{
    mesh my_mesh;
    mesh_it(my_mesh);

    systems my_system= discretize(my_mesh);
    solve(my_system);


    return 0;
}
