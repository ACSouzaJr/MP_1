#makefile
CXX = g++

testa_soma_string_stdin: testa_soma_string_stdin.o string_soma.o
	$(CXX) -g -Wall -o $@ $^

testa_soma_string_stdin.o: testa_soma_string_stdin.c
	$(CXX) -g -Wall -c $<

string_soma.o: string_soma.c string_soma.h
	$(CXX) -g -Wall -c $<

clean:
	rm *.o
