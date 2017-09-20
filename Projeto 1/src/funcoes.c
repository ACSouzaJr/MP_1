#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <funcoes.h>

/** @file */

/**
*   @brief Função que checa se número é negativo.
*   @param Num é um número inteiro.
*   @return true se valido.
*/

bool IsNegative(int Num){

    return Num < 0;
}

/**
*   @brief Função que checa se o número é maior que 1000.
*   @param Num é um número inteiro.
*   @return true se maior que mil.
*/
bool HighValue(int Num){

    return Num > 1000;
}

/**
*   @brief Função que checa se a string possui "\n" no final.
*   @param string_entrada.
*   @return true se valido.
*/
bool NoEnd(const char * string_entrada){

    return (string_entrada[strlen(string_entrada)-1] != '\n');
}

/**
*   @brief  Função que checa se a string possui no minimo 2 números.
*   @param string_entrada.
*   @param delimitadores.
*   @return true se possui entrada invalida.
*/
bool MinNum(const char *string_entrada, char delimitadores[]){

    char *string = strdup(string_entrada);
    string[strlen(string)-1] = '\0';

    return CountNum(string, strcat(delimitadores, "/[]")) < 2;
}

/**
*   @brief Função que checa se a string possui mais de 3 números por linha.
*   @param string_entrada.
*   @param delimitadores.
*   @return true se possui mais de 3 números por linha.
*/
bool LimitLinha(const char * string_entrada, char delimitadores[]){

    char *linha;
    char *string = strdup(string_entrada);

    /**
    *   Conta números por linha.
    */
    while ((linha = strtok_r(string, "\n", &string))){
        if (CountNum(linha, delimitadores) > 3) return true;

    }

    return false;
}

/**
*   @brief  Função que conta número de delimitadores na string.
*   @param string_entrada.
*   @param delimitadores.
*   @return número de delimitadores.
*/
int CountDelimitador(const char *string_entrada, char delimitadores[]){

    char *string = strdup(string_entrada);
    int count = 0;

    /**
    *   Caso possua delimitadores extras, começa a contar a partir do primeiro "\n".
    */
    if (string_entrada[1] == '/')
        strtok_r(string, "\n", &string);

    /**
    *   Conta delimitadores.
    */
    string = strpbrk(string+1, delimitadores);
    while (string != NULL){
        ++count;
        string = strpbrk(string+1, delimitadores);
    }

    return (count/strlen(delimitadores));

}

/**
*   @brief  Função que conta a quantidade de números na string.
*   @param string_entrada.
*   @param delimitadores.
*   @return quantidade de números.
*/
int CountNum(const char * string_entrada, char *delimitadores){

    int count = 0;
    char *c;
    char *linha = strdup(string_entrada);

    /**
    *   Conta números.
    */
    while ((c = strtok_r(linha, delimitadores, &linha))){
            ++count;
    }

    return count;
}

/**
*   @brief  Função que checa se existem delimitadores extras e se possui quantidade de delimitdores válida.
*   @param string_entrada.
*   @return string de delimitadores.
*/
char * Delimitador(const char *string_entrada){

    /**
    *   Verifica se possui delimitadores extras.
    */
    if (string_entrada[1] == '/'){

        /**
        *   Verifica se possui "\n" após a adição de delimtiadores.
        */
        if ((*(strrchr(string_entrada, ']') + 1)) != '\n') return NULL;

        char *entrada = strdup(string_entrada);
        entrada = strtok_r(entrada, "\n", &entrada);

        int ndelimitadores = 0;
        char *delimitadores = (char *) malloc(sizeof(char)*(strrchr(string_entrada, ']') - strchr(string_entrada, '[')));//tamanho

        strcpy(delimitadores, ",/[]");

        /*
        *   Conta delimitadores.
        */
        entrada = strtok(entrada, "/[]");
        while(entrada != NULL){

            strcat(delimitadores, entrada);
            ndelimitadores += CountDelimitador(string_entrada, entrada);
            entrada = strtok(NULL, "/[]");

        }

        //adiciona a virgula como delimitador padrão
        ndelimitadores += CountDelimitador(string_entrada, strdup(","));

        /**
        *   Verifica se quantidade de delimitadores é valida.
        *   Retorna NULL se string_entrada = "//[;]\n1,;2\n"
        */
        if ((CountNum(string_entrada, delimitadores)-1) != ndelimitadores) return NULL;

        return delimitadores;
    }
    else{

        char *delimitadores = strdup(",");
        /**
        *   Verifica se não possui delimitadores extras e se a quantidade de delimitadores é valida.
        *   Retorna NULL se string_entrada = "1,,2\n"
        */
        if (CountDelimitador(string_entrada, delimitadores) != (CountNum(string_entrada, delimitadores)-1)) return NULL;

        return strdup(",");
    }

}
