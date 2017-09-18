#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"


int main(int argc, char const *argv[])
{

    char c;
    int soma;
    char string[200];

    //leitura da stdin
    int i = 0;
    while ((c = fgetc(stdin)) != EOF){
        string[i] = c;
        ++i;
    }
    string[i] = '\0';


    soma = soma_string(string);

    printf("%d\n", soma);


    return 0;
}