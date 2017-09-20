#include <stdio.h>
#include <stdlib.h>
#include <string_soma.h>

/** @file */

/**
*   Arquivo de lê string da entrada padrão, calcula a soma de números positivos e menores que 1000, separados por delimitadores.
*   Retorna a soma se for entrada válido ou -1 se for invalida.
*/

int main(int argc, char const *argv[])
{

    char c;
    int soma;
    char string[200];

    /**
    * Leitura caracter a caracter de stdin.
    */
    int i = 0;
    while (!feof(stdin)){

        c = fgetc(stdin);
        string[i] = c;
        ++i;
    }
    string[i-1] = '\0';

    printf("%s\n", string);

    /**
    *   Execução função de soma.
    *   @see soma_string
    */
    soma = soma_string(string);

    printf("%d\n", soma);


    return 0;
}