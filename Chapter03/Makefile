objects:=*.out *.o *.so *.i *.s
CXXFLAGS+= -g -O0
CXXFLAGS+= -I${MTL}
CXX14FLAGS= ${CXXFLAGS}
CXX14FLAGS+= -std=c++14
CXXFLAGS+= -std=c++11
CXX=g++

template_max: template_max.cc
	${CXX} ${CXXFLAGS} template_max.cc -o template_max.out
template_type_deduction: template_type_deduction.cc
	${CXX} ${CXXFLAGS} template_type_deduction.cc -out template_type_deduction.o
mixingType_max: mixingType_max.cc
	${CXX} ${CXXFLAGS} mixingType_max.cc -o mixingType_max.out

map_test: map_test.cc 
	${CXX} ${CXXFLAGS}  map_test.cc  -o map_test.out

swap_rref: swap_rref.cc
	${CXX} ${CXXFLAGS}  swap_rref.cc -o swap_rref.out

ADL_Test: ADL_Test.cc
	${CXX} ${CXXFLAGS}  ADL_Test.cc -o ADL_Test.out

ADL_Appendix: ADL_Appendix.cc
	${CXX} ${CXXFLAGS}  ADL_Appendix.cc -o ADL_Appendix.out

ADL_Appendix1: ADL_Appendix1.cc
	${CXX} ${CXXFLAGS}  ADL_Appendix1.cc -o ADL_Appendix1.out

vector_template: vector_template.cc
	${CXX} ${CXXFLAGS}  vector_template.cc -o vector_template.out

gen_arr_sum: gen_arr_sum.cc
	${CXX} ${CXXFLAGS}  gen_arr_sum.cc -o gen_arr_sum.out

accumulate_example: accumulate_example.cc
	${CXX} ${CXXFLAGS}  accumulate_example.cc -o accumulate_example.out

value_range_vector: value_range_vector.cc
	${CXX} ${CXX14FLAGS}  value_range_vector.cc -o value_range_vector.out

type_declaration: type_declaration.cc
	${CXX} ${CXXFLAGS}  type_declaration.cc -o type_declaration.out

using_demo: using_demo.cc
	${CXX} ${CXX14FLAGS}  using_demo.cc -o using_demo.out

abs_functor: abs_functor.cc
	${CXX} ${CXX14FLAGS}  abs_functor.cc -o abs_functor.out

fsize_vector: fsize_vector.cc
	${CXX} ${CXXFLAGS}  fsize_vector.cc -o fsize_vector.out

fin_diff: fin_diff.cc
	${CXX} ${CXXFLAGS}  fin_diff.cc -o fin_diff.out

derivative: derivative.cc
	${CXX} ${CXX14FLAGS} -ftemplate-depth=102400 derivative.cc -o derivative.out
	
accumulate_functor_example: accumulate_functor_example.cc
	${CXX} ${CXXFLAGS}  accumulate_functor_example.cc -o accumulate_functor_example.out

lambda: lambda.cc
	${CXX} ${CXXFLAGS}  lambda.cc -o lambda.out

Logical_Operators: Logical_Operators.cc
	${CXX} ${CXXFLAGS}  Logical_Operators.cc -o Logical_Operators.out

Lists_demo: Lists_demo.cc
	${CXX} ${CXXFLAGS}  Lists_demo.cc -o Lists_demo.out

lambda_demo: lambda_demo.cc
	${CXX} ${CXXFLAGS}  lambda_demo.cc -o lambda_demo.out

capture_lambda: capture_lambda.cc
	${CXX} ${CXXFLAGS}  capture_lambda.cc -o capture_lambda.out

variadic_temp: variadic_temp.cc
	${CXX} ${CXXFLAGS}  variadic_temp.cc -o variadic_temp.out

variadic_printf: variadic_printf.cc
	${CXX} ${CXXFLAGS}  variadic_printf.cc -o variadic_printf.out

forwarding_demo: forwarding_demo.cc
	${CXX} ${CXXFLAGS}  forwarding_demo.cc -o forwarding_demo.out

Ex3_1: Ex3_1.cc
	${CXX} ${CXXFLAGS}  Ex3_1.cc -o Ex3_1.out

Ex3_2: Ex3_2.cc
	${CXX} ${CXXFLAGS}  Ex3_2.cc -o Ex3_2.out

Ex3_3_8: Ex3_3_8.cc
	${CXX} ${CXXFLAGS}  Ex3_3_8.cc -o Ex3_3_8.out

Ex3_4: Ex3_4.cc
	${CXX} ${CXXFLAGS}  Ex3_4.cc -o Ex3_4.out

Ex3_5_6: Ex3_5_6.cc
	${CXX} ${CXXFLAGS}  Ex3_5_6.cc -o Ex3_5_6.out

Ex3_11_12: Ex3_11_12.cc
	${CXX} ${CXXFLAGS}  Ex3_11_12.cc -o Ex3_11_12.out

.PHONY: clean
clean:
	-rm edit ${objects}
	echo Clean done
