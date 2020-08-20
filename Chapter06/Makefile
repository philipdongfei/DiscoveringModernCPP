objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXX14FLAGS:= ${CXXFLAGS}
CXXFLAGS+= -std=c++11
CXX14FLAGS+= -std=c++14
CXXUNROLLFLAGS:=-O3 -ffast-math -funroll-loops -DNDEBUG -std=c++11 
CXX=g++-9.3

oop_simple: oop_simple.cc
	${CXX} ${CXXFLAGS} oop_simple.cc -o oop_simple.out

inherit_constructor: inherit_constructor.cc
	${CXX} ${CXXFLAGS} inherit_constructor.cc -o inherit_constructor.out

oop_virtual: oop_virtual.cc
	${CXX} ${CXXFLAGS} oop_virtual.cc -o oop_virtual.out

oop_abstract: oop_abstract.cc
	${CXX} ${CXXFLAGS} oop_abstract.cc -o oop_abstract.out

func_inheritance: func_inheritance.cc
	${CXX} ${CXXFLAGS} func_inheritance.cc -o func_inheritance.out

oop_multi0: oop_multi0.cc
	${CXX} ${CXXFLAGS} oop_multi0.cc -o oop_multi0.out

oop_multi1: oop_multi1.cc
	${CXX} ${CXXFLAGS} oop_multi1.cc -o oop_multi1.out
	
oop_multi2: oop_multi2.cc
	${CXX} ${CXXFLAGS} oop_multi2.cc -o oop_multi2.out

oop_multi3: oop_multi3.cc
	${CXX} ${CXXFLAGS} oop_multi3.cc -o oop_multi3.out

oop_multi4: oop_multi4.cc
	${CXX} ${CXXFLAGS} oop_multi4.cc -o oop_multi4.out

solver_selection_example: solver_selection_example.cc
	${CXX} ${CXXFLAGS} solver_selection_example.cc -o solver_selection_example.out

up_down_cast_example: up_down_cast_example.cc
	${CXX} ${CXXFLAGS} up_down_cast_example.cc -o up_down_cast_example.out

crtp_simple_example: crtp_simple_example.cc
	${CXX} ${CXXFLAGS} crtp_simple_example.cc -o crtp_simple_example.out

matrix_crtp_example: matrix_crtp_example.cc
	${CXX} ${CXXFLAGS} matrix_crtp_example.cc -o matrix_crtp_example.out



.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
