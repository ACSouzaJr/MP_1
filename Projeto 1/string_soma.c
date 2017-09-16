#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"


bool IsNegative(int Num);
bool HighValue(int Num);
bool NoEnd(char * );
bool ManyDelimitador(const char *, char *);

int soma_string(const char* string_entrada){

    //separa a string por delimitadores, a cada separaçao soma numero em soma.
    char *string, *entrada;
    int soma = 0;
    char delimitadores[] = ",";

    //transforma de const para char*
    entrada = strdup(string_entrada);

    //Se possui nao possui  \n no final
    if (NoEnd(entrada)) return -1;

    //Se possui espaço
    if (!(strpbrk(string_entrada, " ") == NULL)) return -1;

    //Se possui delimitadores validos
    if (strpbrk(string_entrada, delimitadores) == NULL) return -1;

    //se tem 2 delimitadores seguidos
    if (ManyDelimitador(string_entrada, delimitadores)) return -1;


    //divide string por delimitadores
    string = strtok(entrada, delimitadores);

    //puts(string);
    //printf("%d\n", strlen(string));


    while(string != NULL){

        if (IsNegative(atoi(string))) return -1; //se x<0 para

        if (!HighValue(atoi(string))){  //se x>1000 ignora

            soma += atoi(string);
        }

        string = strtok(NULL, delimitadores);

    }

    return soma;
}



bool IsNegative(int Num){

    return Num < 0;
}

bool HighValue(int Num){

    return Num > 1000;
}

bool NoEnd(char * string){

    return (string[strlen(string)-1] != '\n');
}

bool ManyDelimitador(const char *string, char delimitadores[]){

    return *(strpbrk(string, delimitadores)) == *(strpbrk(string, delimitadores)+1);
    //return (strpbrk(string, delimitadores) == strpbrk(string+1, delimitadores));
}