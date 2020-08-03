objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXX14FLAGS+= ${CXXFLAGS}
CXXFLAGS+= -std=c++11
CXX14FLAGS+= -std=c++14
CXX=g++-9.3

Iterators_example: Iterators_example.cc
	${CXX} ${CXXFLAGS} Iterators_example.cc -o Iterators_example.out

Containers_example: Containers_example.cc
	${CXX} ${CXXFLAGS} Containers_example.cc -o Containers_example.out

vector_usage: vector_usage.cc
	${CXX} ${CXXFLAGS} vector_usage.cc -o vector_usage.out

deque_emplace: deque_emplace.cc
	${CXX} ${CXXFLAGS} deque_emplace.cc -o deque_emplace.out

List_example: List_example.cc
	${CXX} ${CXXFLAGS} List_example.cc -o List_example.out

Set_example: Set_example.cc
	${CXX} ${CXXFLAGS} Set_example.cc -o Set_example.out

map_test: map_test.cc
	${CXX} ${CXXFLAGS} map_test.cc -o map_test.out

multimap_test: multimap_test.cc
	${CXX} ${CXXFLAGS} multimap_test.cc -o multimap_test.out

unordered_map_test: unordered_map_test.cc
	${CXX} ${CXXFLAGS} unordered_map_test.cc -o unordered_map_test.out

find_test: find_test.cc
	${CXX} ${CXXFLAGS} find_test.cc -o find_test.out

find_test2: find_test2.cc
	${CXX} ${CXXFLAGS} find_test2.cc -o find_test2.out

find_test3: find_test3.cc
	${CXX} ${CXXFLAGS} find_test3.cc -o find_test3.out

find_test4: find_test4.cc
	${CXX} ${CXXFLAGS} find_test4.cc -o find_test4.out

seq_oper: seq_oper.cc
	${CXX} ${CXXFLAGS} seq_oper.cc -o seq_oper.out
	
Numeric_oper: Numeric_oper.cc
	${CXX} ${CXXFLAGS} Numeric_oper.cc -o Numeric_oper.out

#sdl1.2
mandelbrot: mandelbrot.cc
	${CXX} ${CXXFLAGS} `sdl-config --cflags --libs`  mandelbrot.cc -o mandelbrot.out
	
mixed_complex: mixed_complex.cc
	${CXX} ${CXXFLAGS} `sdl-config --cflags --libs`  mixed_complex.cc -o mixed_complex.out


random_testing: random_testing.cc
	${CXX} ${CXXFLAGS}  random_testing.cc -o random_testing.out

Engines_testing: Engines_testing.cc
	${CXX} ${CXXFLAGS}  Engines_testing.cc -o Engines_testing.out

Distribution_testing: Distribution_testing.cc
	${CXX} ${CXXFLAGS}  Distribution_testing.cc -o Distribution_testing.out

black_scholes: black_scholes.cc
	${CXX} ${CXXFLAGS}  black_scholes.cc -o black_scholes.out

print_diff_float: print_diff_float.cc
	${CXX} ${CXXFLAGS}  print_diff_float.cc -o print_diff_float.out

type_traits_example: type_traits_example.cc
	${CXX} ${CXXFLAGS}  type_traits_example.cc -o type_traits_example.out

memcpy_test: memcpy_test.cc
	${CXX} ${CXXFLAGS}  memcpy_test.cc -o memcpy_test.out

tuple_move_test: tuple_move_test.cc
	${CXX} ${CXXFLAGS}  tuple_move_test.cc -o tuple_move_test.out

boost_fusion_example: boost_fusion_example.cc
	${CXX} ${CXXFLAGS}  boost_fusion_example.cc -o boost_fusion_example.out

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
