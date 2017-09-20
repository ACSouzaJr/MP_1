#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string_soma.h>
#include <funcoes.h>

/** @file */

/**
*   @brief Funcao que decide se a entrada é valida e retorna a soma da string.
*   @param strig_entrada: entrada a ser analisada.
*   @return retorna a soma se for valido.
*/


int soma_string(const char* string_entrada){

    //separa a string por delimitadores, a cada separaçao soma numero em soma.
    char *string, *entrada;
    int soma = 0;
    char *delimitadores;

    //transforma de const para char*
    entrada = strdup(string_entrada);   /*< copia entrada para variável manipulavel. */

    /**
    *   Verifica se a entrada possui delimitadores extras.
    *   @see Delimitador
    */
    if((delimitadores = Delimitador(string_entrada)) == NULL) return -1;

    /**
    *   Verifica se a entrada possui "\n" no final da string entrada.
    *   @see NoEnd
    */
    if (NoEnd(string_entrada)) return -1;

    /**
    *   Verifica se possuem espaços na entrada.
    */
    if (!(strpbrk(string_entrada, " ") == NULL)) return -1;

    /**
    *   Verifica se a entrada possui delimitadores válidos.
    */
    if (strpbrk(string_entrada, delimitadores) == NULL) return -1;

    /**
    *   Verifica se a entrada possui mais de um número.
    *   @see MinNum
    */
    if (MinNum(string_entrada, delimitadores)) return -1;

    /**
    *   Verifica se possui mais de 3 números por linha.
    *   @see LimitLinha
    */
    if (LimitLinha(string_entrada, delimitadores)) return -1;


    /**
    *    Divide string por delimitadores e faz a soma dos números.
    */
    string = strtok(entrada, delimitadores);

    while(string != NULL){

        /**
        *   Verifica se o número é negativo
        *   @see IsNegative
        */
        if (IsNegative(atoi(string))) return -1; //se x<0 para

        /**
        *   Verifica se o número é maior que 1000
        *   @see HighValue
        */
        if (!HighValue(atoi(string))){  //se x>1000 ignora

            soma += atoi(string);
        }

        string = strtok(NULL, delimitadores);

    }

    return soma;
}


