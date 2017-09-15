#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"

bool IsNegative(int Num);
bool HighValue(int Num);
bool NoEnd(const char * string_entrada);

int soma_string(const char* string_entrada){

    //separa a string por delimitadores, a cada separaçao soma numero em soma.
    char *string, *entrada;
    int soma = 0;

    //Se possui nao possui  \n no final
    if (NoEnd(string_entrada)) return -1;


    //transforma de const para char*
    entrada = strdup(string_entrada);
    string = strtok(entrada, ",");


    while(string != NULL){

        if (IsNegative(atoi(string))) return -1; //se x<0 para

        if (!HighValue(atoi(string))){  //se x> 1000 ignora

            soma += atoi(string);
        }
        //puts(string);
        string = strtok(NULL, ", ");

    }

    return soma;
}

bool IsNegative(int Num){

    return Num < 0;
}

bool HighValue(int Num){

    return Num > 1000;
}

bool NoEnd(const char * string_entrada){

    return (strrchr(string_entrada, '\n') == NULL || !(strrchr(string_entrada, '\n') == (string_entrada + (strlen(string_entrada)-1))));
}