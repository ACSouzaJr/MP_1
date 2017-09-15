#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"

int soma_string(const char* string_entrada){

    //separa a string por delimitadores, a cada separaçao soma numero em soma.
    char *string, *entrada;
    int soma = 0;

    //trsnsforma de const para char*
    entrada = strdup(string_entrada);
    string = strtok(entrada, ",");

    while(string != NULL){

        soma += atoi(string);
        //puts(string);
        string = strtok(NULL, ", ");

    }

    return soma;
}