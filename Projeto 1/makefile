#makefile

testa_soma_string_stdin: testa_soma_string_stdin.o string_soma.o
	gcc -g -Wall -o $@ $^

testa_soma_string_stdin.o: testa_soma_string_stdin.c
	gcc -g -Wall -c $<

string_soma.o: string_soma.c string_soma.h
	gcc -g -Wall -c $^

clean:
	rm *.o
