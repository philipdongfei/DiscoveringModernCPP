#ifndef GREATEST_BESTEST_SOLVER_INCLUDE
#define GREATEST_BESTEST_SOLVER_INCLUDE

#include "mesher.hpp"

struct systems {  }; // modify struct name from system to systems

systems discretize(const mesh& m);

void solve(systems& s);

#endif // GREATEST_BESTEST_SOLVER_INCLUDE

