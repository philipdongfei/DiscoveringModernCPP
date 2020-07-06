objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXXFLAGS+= -std=c++11
CXX=g++

complex_test: complex_test.cc complex.h
	${CXX} ${CXXFLAGS} complex_test.cc -o complex_test.o
vector_test: vector_test.cc
	${CXX} ${CXXFLAGS} vector_test.cc -o vector_test.o
vector_unique_ptr: vector_unique_ptr.cc
	${CXX} ${CXXFLAGS} vector_unique_ptr.cc -o vector_unique_ptr.o
occi_old_style: occi_old_style.cc
	${CXX} ${CXXFLAGS} -locci occi_old_style.cc -o occi_old_style.o
occi_resource_rescue: occi_resource_rescue.cc
	${CXX} ${CXXFLAGS} -locci occi_resource_rescue.cc -o occi_resource_rescue.o

complex_def_oper: complex_def_oper.cc
	${CXX} ${CXXFLAGS}  complex_def_oper.cc -o complex_def_oper.o
polynomial: polynomial.cc
	${CXX} ${CXXFLAGS}  polynomial.cc -o polynomial.o



.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
