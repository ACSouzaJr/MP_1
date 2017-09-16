#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"


bool IsNegative(int Num);
bool HighValue(int Num);
bool NoEnd(const char * );
bool ManyDelimitador(const char *, char *);
bool LimitLinha(const char *, char *);
int CountNum(const char *, char *);
bool MinNum(const char *, char *);

int soma_string(const char* string_entrada){

    //separa a string por delimitadores, a cada separaçao soma numero em soma.
    char *string, *entrada;
    int soma = 0;
    char delimitadores[] = ",";

    //transforma de const para char*
    entrada = strdup(string_entrada);

    //Se possui nao possui  \n no final
    if (NoEnd(string_entrada)) return -1;

    //Se possui espaço
    if (!(strpbrk(string_entrada, " ") == NULL)) return -1;

    //Se possui delimitadores validos
    if (strpbrk(string_entrada, delimitadores) == NULL) return -1;

    //se tem 2 delimitadores seguidos
    if (ManyDelimitador(string_entrada, delimitadores)) return -1;

    //menos de 2 numeros
    if (MinNum(string_entrada, delimitadores)) return -1;

    //0 a 3 num por linha
    if (LimitLinha(string_entrada, delimitadores)) return -1;


    //divide string por delimitadores
    string = strtok(entrada, delimitadores);

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

bool NoEnd(const char * string){

    return (string[strlen(string)-1] != '\n');
}

bool ManyDelimitador(const char *string, char delimitadores[]){

    return *(strpbrk(string, delimitadores)) == *(strpbrk(string, delimitadores)+1);
}

bool LimitLinha(const char * string_entrada, char delimitador[]){

    char *linha;
    char *string = strdup(string_entrada);


    while ((linha = strtok_r(string, "\n", &string))){
        if (CountNum(linha, delimitador) > 3) return true;

    }

    return false;
}

int CountNum(const char * string, char *delimitador){

    int count = 0;
    char *c;
    char *linha = strdup(string);

    while ((c = strtok_r(linha, delimitador, &linha))){
            count++;
    }

    return count;
}

bool MinNum(const char *string_entrada, char delimitador[]){

    char *string = strdup(string_entrada);
    string[strlen(string)-1] = '\0';

    return CountNum(string, delimitador) < 2;
}