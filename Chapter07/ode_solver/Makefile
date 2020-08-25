objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXX14FLAGS:= ${CXXFLAGS}
CXX17FLAGS:= ${CXXFLAGS}
CXXFLAGS+= -std=c++11
CXX14FLAGS+= -std=c++14
CXX17FLAGS+= -std=c++17
CXX=g++-9.3

lorenz: lorenz.cc algebra.hpp operations.hpp resize.hpp runge_kutta4.hpp
	${CXX} ${CXXFLAGS} lorenz.cc -o lorenz.out

.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
