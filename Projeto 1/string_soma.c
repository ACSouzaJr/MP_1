#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"

int IsNegative(int Num);
int HighValue(int Num);

int soma_string(const char* string_entrada){

    //separa a string por delimitadores, a cada separaçao soma numero em soma.
    char *string, *entrada;
    int soma = 0;

    //trsnsforma de const para char*
    entrada = strdup(string_entrada);
    string = strtok(entrada, ",");

    while(string != NULL){

        if (IsNegative(atoi(string))) return -1;
        //if (!HighValue(atoi(string)))


        soma += atoi(string);
        //puts(string);
        string = strtok(NULL, ", ");



    }

    return soma;
}

int IsNegative(int Num){

    return Num < 0 ? 1:0;
}

/*int HighValue(int Num){

    return Num > 1000 ? 1:0;
}*/