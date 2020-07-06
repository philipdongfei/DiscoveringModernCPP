#!/bin/bash

#valgrind --tool=memcheck ./vector_test.o

valgrind --tool=memcheck -v --leak-check=full \
         --show-leak-kinds=all ./vector_test.o


