IDIR =../header
CXX = g++
CFLAGS=-I$(IDIR)

ODIR=obj

#CXXFLAGS += -g -Wall -Wextra -pthread -Weffc++
GTESTFLAGS += -lgtest -lgtest_main -lpthread


ifeq ($(MAKECMDGOALS),teste)
	CXXFLAGS += -g -Wall -Wextra -pthread -Weffc++ -ftest-coverage -fprofile-arcs
else
	CXXFLAGS += -g -Wall -Wextra -pthread -Weffc++
endif

#main
MAIN = testa_soma_string_stdin

_DEPS = funcoes.h string_soma.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_soma_string_stdin.o string_soma.o funcoes.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#teste
TESTE = testa_string_soma

_OBJT = testa_string_soma.o string_soma.o funcoes.o
OBJT = $(patsubst %,$(ODIR)/%,$(_OBJT))


all: main

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $^ $(CFLAGS)

teste: $(OBJT)
	$(CXX) $(CXXFLAGS) -o $(TESTE) $^ $(CFLAGS) $(GTESTFLAGS)

.PHONY: clean gcov check

clean:
	-rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	-rm $(ODIR)/*.gcda $(ODIR)/*.gcno
	-rm testa_string_soma testa_soma_string_stdin

check:
	cppcheck --enable=warning .

gcov:
	gcovr -r .

