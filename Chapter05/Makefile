objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXX14FLAGS:= ${CXXFLAGS}
CXXFLAGS+= -std=c++11
CXX14FLAGS+= -std=c++14
CXXUNROLLFLAGS:=-O3 -ffast-math -funroll-loops -DNDEBUG -std=c++11 
CXX=g++-9.3

unruh: unruh.cc
	${CXX} ${CXXFLAGS} -fpermissive unruh.cc -o unruh.out

fibonacci: fibonacci.cc
	${CXX} ${CXXFLAGS} fibonacci.cc -o fibonacci.out

popcount: popcount.cc
	${CXX} ${CXXFLAGS} popcount.cc -o popcount.out

is_prime: is_prime.cc
	${CXX} ${CXXFLAGS} is_prime.cc -o is_prime.out

Constant_test: Constant_test.cc
	${CXX} ${CXXFLAGS} Constant_test.cc -o Constant_test.out

magnitude_example: magnitude_example.cc
	${CXX} ${CXXFLAGS} magnitude_example.cc -o magnitude_example.out

vector_noexcept: vector_noexcept.cc
	${CXX} ${CXXFLAGS} vector_noexcept.cc -o vector_noexcept.out

trans_const: trans_const.cc
	${CXX} ${CXX14FLAGS} trans_const.cc -o trans_const.out


enable_if_test: enable_if_test.cc
	${CXX} ${CXXFLAGS} enable_if_test.cc -o enable_if_test.out

variadic_func: variadic_func.cc
	${CXX} ${CXXFLAGS} variadic_func.cc -o variadic_func.out
	
expression_template_example: expression_template_example.cc
	${CXX} ${CXXFLAGS} expression_template_example.cc -o expression_template_example.out


expression_template_example2: expression_template_example2.cc
	${CXX} ${CXXFLAGS}  expression_template_example2.cc -o expression_template_example2.out

fsize_unroll_test: fsize_unroll_test.cc
	${CXX} ${CXXFLAGS}  fsize_unroll_test.cc -o fsize_unroll_test.out

vector_unroll_example: vector_unroll_example.cc
	${CXX} ${CXXUNROLLFLAGS}  vector_unroll_example.cc -o vector_unroll_example.out

vector_unroll_example2: vector_unroll_example2.cc
	${CXX} ${CXXUNROLLFLAGS}  vector_unroll_example2.cc -o vector_unroll_example2.out

reduction_unroll_example: reduction_unroll_example.cc
	${CXX} ${CXXUNROLLFLAGS}  reduction_unroll_example.cc -o reduction_unroll_example.out

reduction_unroll_array_example: reduction_unroll_array_example.cc
	${CXX} ${CXXUNROLLFLAGS}  reduction_unroll_array_example.cc -o reduction_unroll_array_example.out

reduction_unroll_nesting_example: reduction_unroll_nesting_example.cc
	${CXX} ${CXXUNROLLFLAGS}  reduction_unroll_nesting_example.cc -o reduction_unroll_nesting_example.out

reduction_unroll_registers_example: reduction_unroll_registers_example.cc
	${CXX} ${CXXUNROLLFLAGS}  reduction_unroll_registers_example.cc -o reduction_unroll_registers_example.out

matrix_unroll_example: matrix_unroll_example.cc
	${CXX} ${CXXUNROLLFLAGS}  matrix_unroll_example.cc -o matrix_unroll_example.out

tuple_test: tuple_test.cc Tuple.hpp
	${CXX} ${CXXFLAGS}  tuple_test.cc -o tuple_test.out

function_example: function_example.cc Tuple.hpp
	${CXX} ${CXXFLAGS}  function_example.cc -o function_example.out

ref_example: ref_example.cc Tuple.hpp
	${CXX} ${CXXFLAGS}  ref_example.cc -o ref_example.out

chrono_example: chrono_example.cc Tuple.hpp
	${CXX} ${CXXFLAGS}  chrono_example.cc -o chrono_example.out

Ex4_1: Ex4_1.cc Tuple.hpp
	${CXX} ${CXXFLAGS}  Ex4_1.cc -o Ex4_1.out

Ex4_2: Ex4_2.cc Tuple.hpp
	${CXX} ${CXXFLAGS}  Ex4_2.cc -o Ex4_2.out

Ex4_3: Ex4_3.cc
	${CXX} ${CXXFLAGS} `sdl-config --cflags --libs`  Ex4_3.cc -o Ex4_3.out

.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
