objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXXFLAGS+= -std=c++11
CXX=g++

hello42: hello42.cc
	${CXX} ${CXXFLAGS} hello42.cc -o hello42.o
hiding_demo: hiding_demo.cc
	${CXX} ${CXXFLAGS} hiding_demo.cc -o hiding_demo.o
num_1: num_1.cc
	${CXX} ${CXXFLAGS} num_1.cc -o num_1.o
collatz: collatz.cc
	${CXX} ${CXXFLAGS} collatz.cc -o collatz.o
eps: eps.cc
	${CXX} ${CXXFLAGS} eps.cc -o eps.o
loop_demo: loop_demo.cc
	${CXX} ${CXXFLAGS} loop_demo.cc -o loop_demo.o
taylorSeries: taylorSeries.cc
	${CXX} ${CXXFLAGS} taylorSeries.cc -o taylorSeries.o
range_based: range_based.cc
	${CXX} ${CXXFLAGS} range_based.cc -o range_based.o
overload_testing: overload_testing.cc
	${CXX} ${CXXFLAGS} overload_testing.cc -o overload_testing.o
argc_argv_test: argc_argv_test.cc
	${CXX} ${CXXFLAGS} argc_argv_test.cc -o argc_argv_test.o
input_output_explicit: input_output_explicit.cc
	${CXX} ${CXXFLAGS} input_output_explicit.cc -o input_output_explicit.o
input_output_implicit: input_output_implicit.cc
	${CXX} ${CXXFLAGS} input_output_implicit.cc -o input_output_implicit.o
stream_example: stream_example.cc
	${CXX} ${CXXFLAGS} stream_example.cc -o stream_example.o
formatting: formatting.cc
	${CXX} ${CXXFLAGS} formatting.cc -o formatting.o
IOError_Simple_Example: IOError_Simple_Example.cc
	${CXX} ${CXXFLAGS} IOError_Simple_Example.cc -o IOError_Simple_Example.o
IOError_Wrong: IOError_Wrong.cc
	${CXX} ${CXXFLAGS} IOError_Wrong.cc -o IOError_Wrong.o
unique_ptr_example: unique_ptr_example.cc
	${CXX} ${CXXFLAGS} unique_ptr_example.cc -o unique_ptr_example.o
Uni_Ptr_Example: Uni_Ptr_Example.cc
	${CXX} ${CXXFLAGS} Uni_Ptr_Example.cc -o Uni_Ptr_Example.o
shared_ptr_example: shared_ptr_example.cc
	${CXX} ${CXXFLAGS} shared_ptr_example.cc -o shared_ptr_example.o
Shared_Ptr_Demo: Shared_Ptr_Demo.cc
	${CXX} ${CXXFLAGS} -pthread Shared_Ptr_Demo.cc -o Shared_Ptr_Demo.o
weak_ptr_demo: weak_ptr_demo.cc
	${CXX} ${CXXFLAGS} weak_ptr_demo.cc -o weak_ptr_demo.o
vector_example: vector_example.cc
	${CXX} ${CXXFLAGS}  vector_example.cc -o vector_example.o
valarray_example: valarray_example.cc
	${CXX} ${CXXFLAGS}  valarray_example.cc -o valarray_example.o
Ex1_10_1: Ex1_10_1.cc
	${CXX} ${CXXFLAGS}  Ex1_10_1.cc -o Ex1_10_1.o
Ex1_10_3: Ex1_10_3.cc
	${CXX} ${CXXFLAGS}  Ex1_10_3.cc -o Ex1_10_3.o





.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
