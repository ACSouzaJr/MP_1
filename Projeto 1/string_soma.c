#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"

char *Delimitador(const char *);
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
    char *delimitadores;

    //transforma de const para char*
    entrada = strdup(string_entrada);

    //verifica se tem novos delimitadores
    if((delimitadores = Delimitador(string_entrada)) == NULL) return -1;

    //verifica se possui  \n no final
    if (NoEnd(string_entrada)) return -1;

    //verifica se possui espaço
    if (!(strpbrk(string_entrada, " ") == NULL)) return -1;

    //verifica se possui delimitadores validos
    if (strpbrk(string_entrada, delimitadores) == NULL) return -1;

    //verifica se possui apenas 1 numero
    if (MinNum(string_entrada, delimitadores)) return -1;

    //verifica se possui 0 a 3 num por linha
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

bool MinNum(const char *string_entrada, char delimitador[]){

    char *string = strdup(string_entrada);
    string[strlen(string)-1] = '\0';

    return CountNum(string, strcat(delimitador, "/[]")) < 2;
}

bool LimitLinha(const char * string_entrada, char delimitador[]){

    char *linha;
    char *string = strdup(string_entrada);


    while ((linha = strtok_r(string, "\n", &string))){
        if (CountNum(linha, delimitador) > 3) return true;

    }

    return false;
}

int CountDelimitador(const char *string_entrada, char delimitadores[]){

    char *string = strdup(string_entrada);
    int count = 0;

    //se possuir delimitadores extras
    if (string_entrada[1] == '/')
        strtok_r(string, "\n", &string);

    string = strpbrk(string+1, delimitadores);
    while (string != NULL){
        ++count;
        string = strpbrk(string+1, delimitadores);
    }

    return (count/strlen(delimitadores));

}

int CountNum(const char * string, char *delimitador){

    int count = 0;
    char *c;
    char *linha = strdup(string);

    while ((c = strtok_r(linha, delimitador, &linha))){
            ++count;
    }

    return count;
}


char * Delimitador(const char *string_entrada){

    if (string_entrada[1] == '/'){

        if ((*(strrchr(string_entrada, ']') + 1)) != '\n') return NULL;

        char *entrada = strdup(string_entrada);
        entrada = strtok_r(entrada, "\n", &entrada);

        int ndelimitador = 0;
        char *delimitador = (char *) malloc(sizeof(char)*(strrchr(string_entrada, ']') - strchr(string_entrada, '[')));//tamanho

        strcpy(delimitador, ",/[]");

        entrada = strtok(entrada, "/[]");
        while(entrada != NULL){

            strcat(delimitador, entrada);
            ndelimitador += CountDelimitador(string_entrada, entrada);
            entrada = strtok(NULL, "/[]");

        }

        //caso possua a virgula
        ndelimitador += CountDelimitador(string_entrada, strdup(","));

        //se nao possui delimitadores validos
        if ((CountNum(string_entrada, delimitador)-1) != ndelimitador) return NULL;

        return delimitador;
    }
    else{

        char *delimitador = strdup(",");

        if (CountDelimitador(string_entrada, delimitador) != (CountNum(string_entrada, delimitador)-1)) return NULL;

        return strdup(",");
    }

}