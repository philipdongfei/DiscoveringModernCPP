objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXX14FLAGS:= ${CXXFLAGS}
CXX17FLAGS:= ${CXXFLAGS}
CXXFLAGS+= -std=c++11
CXX14FLAGS+= -std=c++14
CXX17FLAGS+= -std=c++17
CXXUNROLLFLAGS:=-O3 -ffast-math -funroll-loops -DNDEBUG -std=c++11 
CXX=g++-9.3

trajectory_Lorenz: trajectory_Lorenz.cc rk4.hpp
	${CXX} ${CXX17FLAGS} trajectory_Lorenz.cc -o trajectory_Lorenz.out





.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
