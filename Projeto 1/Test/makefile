#Compilador
CXX = g++
# Where to find user code.
USER_DIR = ..

OBJ = obj

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread  -Weffc++

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = sample1_unittest

all : $(TESTS)

clean:
	rm *.o

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

#codigo a ser testado
string_soma.o : $(USER_DIR)/string_soma.c $(USER_DIR)/string_soma.h
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/string_soma.c

#codigo de rotina de testes
testa_string_soma.o : testa_string_soma.c
	$(CXX) $(CXXFLAGS) -c testa_string_soma.c -I..

#junçao das funcoes com o header de teste
sample1_unittest : testa_string_soma.o string_soma.o
	$(CXX) $(CXXFLAGS)  -o $@ $^  -lgtest -lgtest_main -lpthread

